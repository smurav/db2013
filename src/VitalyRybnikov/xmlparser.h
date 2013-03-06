/*
 * xmlparser.h
 *
 * Copyright 2013 Vitaly Rybnikov <Vitaly.Rybnikov@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/* This class is a simple xml-parser(SAX-based).
 * It read xml-file, scan it, and emits events to xml-handler
 */

#ifndef XMLPARSER_H
#define XMLPARSER_H



#include "xmlhandler.h"


class XMLParser
{
    public:
        XMLParser(XMLHandler *handler);
        ~XMLParser();

    private:
        XMLHandler  *_handler;
};

#endif /* XMLPARSER_H */
