#include <cstdio>
#include <cstdlib>
#include <assert.h>

#include "xml_libxml.h"
#include <libxml/xmlreader.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>


// Main validation process
bool validateFileWithDTD(const char *filename)
{
#ifdef LIBXML_READER_ENABLED

    bool result = false;
    xmlTextReaderPtr reader;
    int ret;

    reader = xmlReaderForFile(filename, 0,
                        XML_PARSE_DTDATTR |  /* default DTD attributes */
                        XML_PARSE_DTDVALID); /* validate with the DTD */

    if (0 != reader)
    {
        ret = xmlTextReaderRead(reader);
        while (1 == ret) {
            ret = xmlTextReaderRead(reader);
        }

        /* document has been fully parsed -> check the validation results
         */
        if (1 != xmlTextReaderIsValid(reader)) {
            fprintf(stderr, "Document %s does not validate\n", filename);
            result = false;
        } else {
            result = true;
        }

        xmlFreeTextReader(reader);
        if (0 != ret ) {
            fprintf(stderr, "%s : failed to parse\n", filename);
            result = false;
        }
    }
    else
    {
        fprintf(stderr, "Unable to open %s\n", filename);
        result = false;
    }


    // ?..
    xmlCleanupParser();
    xmlMemoryDump();

    return result;
#else
    fprintf(stderr, "XInclude (DTD) support not compiled in\n");
    exit(1);
#endif
}


/**
 * execute_xpath_expression:
 * @xpathExpr:      the xpath expression for evaluation.
 *
 * Parses input XML file @_fileName, evaluates XPath expression and ....?!
 *
 * Returns 0 on success and a negative value otherwise.
 */
int execute_xpath_expression(const char *filename, const xmlChar *xpathExpr)
{
#if defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_SAX1_ENABLED)

    xmlDocPtr doc;
    xmlXPathContextPtr xpathCtx;
    xmlXPathObjectPtr xpathObj;

    assert(filename);
    assert(xpathExpr);

    /* Init libxml */
    xmlInitParser();
    LIBXML_TEST_VERSION

    /* Load XML document */
    doc = xmlParseFile(filename);
    if (0 == doc) {
        fprintf(stderr, "Error: unable to parse file \"%s\"\n", filename);
        return (-1);
    }

    /* Create xpath evaluation context */
    xpathCtx = xmlXPathNewContext(doc);
    if (0 == xpathCtx) {
        fprintf(stderr,"Error: unable to create new XPath context\n");
        xmlFreeDoc(doc);
        return (-1);
    }

    /* Evaluate xpath expression */
    xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    if (0 == xpathObj) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return (-1);
    }

    // Executing done.




    /* Cleanup */
    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
    /* Shutdown libxml */
    xmlCleanupParser();

    return 0;
#else
    fprintf(stderr, "XPath support not compiled in\n");
    exit(1);
#endif
}

