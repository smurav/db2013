#ifndef XML_LIBXML_H
#define XML_LIBXML_H

// Some common functions

#include <libxml/parser.h>

class QStandardItemModel;

// Validate 'filename' with DTD
bool validateFileWithDTD(const char *filename);


int execute_xpath_expression(const char* filename,
                             const xmlChar *xpathExpr,
                             QStandardItemModel *model);

void printElementNames(xmlNode * a_node);

void printSpaces(int count);

#endif // XML_LIBXML_H
