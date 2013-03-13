#include "xmlstructuretreeview.h"
#include <QApplication>
#include <QTextCodec>

#include <cstdio>

#include <libxml/tree.h>
#include <libxml/parser.h>

void help(char *programName);
void printXMLThreeInConsole_university(char *fileName);
void printSpaces(int count);
void printElementNames(xmlNode * a_node);

int main(int argc, char *argv[])
{
    char helpParam[] = "-h";
    char consoleModeParam[] = "-c";
    char versionParam[] = "-v";

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));


    if (argc == 1)
    {
        // just start graphic
        QApplication a(argc, argv);
        XMLStructureTreeView w;
        w.show();
        return a.exec();
    }

    if (argc > 1)   // at least we have 1 arg: argv[0] - program name
    {
        if (strcmp(argv[1], helpParam) == 0)
        {
            help(argv[0]);
            exit(0);
        }

        if (strcmp(argv[1], versionParam) == 0)
        {
            printf("Version: 0.0.1\n");
            exit(0);
        }
    }

    if (argc == 2)  // graphic mode, fileName specified || -c without param
    {
        if (strcmp(argv[1], consoleModeParam) == 0)
        {
            // user didn't specified filename for console mode
            help(argv[0]);
            exit(0);
        }

        // graphic mode, fileName specified
        QApplication a(argc, argv);
        XMLStructureTreeView w(0, argv[1]);    // ( *parent, *fileName)
        w.show();
        return a.exec();
    }

    if (argc == 3) {
        if (strcmp(argv[1], consoleModeParam) == 0)
        {
            // console mode, hope with correct filename
            printXMLThreeInConsole_university(argv[2]);
            exit(0);
        }
    }

    return 0;
}

//------------------------------------------------------------------------------
// Print Help
void help(char *programName)
{
    printf("usage: %s [option] [file Name]\n", programName);
    printf("OPTIONS:\n");
    printf("  -c\tRun in console; need to specify filename\n");
    printf("  -h\tShow this help\n");
}

//-------------------------------

// Print XML structure as Three in console
void printXMLThreeInConsole_university(char *fileName)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    /*parse the file and get the DOM */
    doc = xmlReadFile(fileName, NULL, 0);

    if (doc == NULL) {
        fprintf(stderr, "error: could not parse file %s\n", fileName);
        return;
    }

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    if (root_element == NULL) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return;
    }

    // good to use DTD for that, or smth else
    if (xmlStrcmp(root_element->name, (const xmlChar *) "university"))
    {
            fprintf(stderr,"document of the wrong type, root node != university\n");
            xmlFreeDoc(doc);
            return;
    }

    // ok, let's lastly print three)))
    printElementNames(root_element);

    /*free the document */
    xmlFreeDoc(doc);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();
}

//-------------------------------
// Print 'count' spaces (need to draw 'fake three' in console)
void printSpaces(int count)
{
    printf("*|");
    for (int k = 1; k <= count; ++k)
    {
        printf("--");
        if ( (k) % 2)
            printf("|");
    }
}

//-------------------------------
// Print Names for given node 'a_node'
// for this node, sibling, and their childs (recursivle)
void printElementNames(xmlNode * a_node)
{
    xmlNode *cur_node = NULL;
//    int k = 0;
    static int deep = 0;    // current deep-level in three-hierarchy

    // go along one deep-level (this->brother1->broter2->...)
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
//                ++k;
            printSpaces(deep);
            // print:  'helpful integer _ attribute name = attribute value'
            //          for firsts attrbs
//            printf("%d _ %s = %s\n", k, cur_node->properties->name,
//                                      cur_node->properties->children->content
//                                        );
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









