#include <cstdio>
#include <cstdlib>

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
int execute_xpath_expression(const xmlChar *xpathExpr)
{
    #if defined(LIBXML_XPATH_ENABLED) && defined(LIBXML_SAX1_ENABLED)
    return 0;

    #else
    fprintf(stderr, "XPath support not compiled in\n");
    exit(1);
    #endif
}

