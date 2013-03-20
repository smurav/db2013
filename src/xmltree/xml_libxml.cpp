#include "xml_libxml.h"
#include <libxml/xmlreader.h>
#include <cstdio>
#include <cstdlib>

// Main validation process
bool validateFileWithDTD(const char *filename)
{
#ifdef LIBXML_READER_ENABLED

    bool result = false;


    return result;
#else
    fprintf(stderr, "XInclude (DTD) support not compiled in\n");
    exit(1);
#endif
}

// validate helper


