#include <QApplication>
#include <QTextCodec>
#include <cstdio>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "xmlstructuretreeview.h"
#include "xml_libxml.h"


void help (char *programName);
void printXMLThreeInConsole_university (char *fileName);


int main(int argc, char *argv[])
{
    char helpParam[] = "-h";
    char consoleModeParam[] = "-c";
    char versionParam[] = "-v";

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    // we have at least 1 arg: argv[0] - program name
    if (argc == 1)
    {
        // just start graphic
        QApplication a(argc, argv);
        XMLStructureTreeView w;
        w.show();
        return a.exec();
    }

    if (argc > 1)
    {
        if (strcmp(argv[1], helpParam) == 0) {
            help(argv[0]);
            exit(0);
        }
        if (strcmp(argv[1], versionParam) == 0) {
            printf("Version: 1.1.0\n");
            exit(0);
        }
    }

    if (argc == 2)  // graphic mode, fileName specified || -c without param
    {
        if (strcmp(argv[1], consoleModeParam) == 0) {
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

    if (argc == 3)
    {
        if (strcmp(argv[1], consoleModeParam) == 0) {
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


//--------------------------------------------------------------------------------


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

    if (0 == doc) {
        fprintf(stderr, "error: could not parse file %s\n", fileName);
        return;
    }

    /* Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    if (0 == root_element) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return;
    }

    /* validate file with DTD
     **/
    if (!validateFileWithDTD(fileName)) {
        fprintf(stderr, "DTD error. Stop.\n");
        xmlFreeDoc(doc);
        exit(-1);
    }


    // ok, let's print three
    printElementNames(root_element);

    /*free the document */
    xmlFreeDoc(doc);
    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();
}



