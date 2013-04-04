#include <cstdio>
#include <cstdlib>
#include <assert.h>

#include <libxml/xpathInternals.h>
#include <libxml/xmlreader.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

#include <QStandardItemModel>
#include <QDebug>

#include "xml_libxml.h"


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
//    xmlMemoryDump();

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
    qDebug() << "executing fin.";
    printf("%s\n", "executing fin.");


    // Print results
    // TODO: print it in gui (save in model? )
    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    xmlNodePtr cur;
    int size;
    int i;

    size = (nodes) ? nodes->nodeNr : 0;

    fprintf(stdout, "Result (%d nodes):\n", size);
    for(i = 0; i < size; ++i)
    {
        assert(nodes->nodeTab[i]);

        if(nodes->nodeTab[i]->type == XML_ELEMENT_NODE)
        {
            cur = nodes->nodeTab[i];
            if (cur->ns) {
//                fprintf(stdout, "|= element node \"%s:%s\"\n",
//                                        cur->ns->href, cur->name);
            } else {
                    xmlChar *uri;
                    uri = xmlGetProp(cur, (xmlChar *)"name");
                    if (uri)
                        printf("|*%s\n", uri);

                printElementNames(cur->children);
            }
        }
    }

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


// Print Names for given node @a_node
// for this node, sibling, and their childs (recursivle)
void printElementNames(xmlNode *a_node)
{
    xmlNode *cur_node = NULL;
    static int deep = 0;    // current deep-level in three-hierarchy

    // go along one deep-level (this->brother1->broter2->...)
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            printSpaces(deep);

            xmlChar *uri;
            // We interested only in attrs 'name'
            uri = xmlGetProp(cur_node, (xmlChar *)"name");
            if (uri)
                printf("%s\n", uri);
            else                    // perhaps, it's 'group' tag
                printf("%s %s, %s\n", cur_node->name,
                       xmlGetProp(cur_node, (xmlChar *)"number"),
                       xmlGetProp(cur_node, (xmlChar *)"entering")
                       );
        }
        // print information about children
        deep++;
        printElementNames(cur_node->children);
        deep--; // all done, go to the next brother
    }
}


// Print 'count' spaces (need to draw 'fake three' in console)
void printSpaces(int count)
{
    printf("*|");
    for (int k = 1; k <= count; ++k) {
        printf("%s%s", "--", (k % 2) ? "|" : "");
    }
}

