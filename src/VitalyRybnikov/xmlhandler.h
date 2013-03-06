/*
 * xmlhandler.h
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

/* This class implements logic of
 * event-based model of working woth xml-file.
 * It catch all events from parser and decide what to do
 */

#include "xmldata.h"


#ifndef XMLHANDLER_H
#define XMLHANDLER_H

class XMLHandler
{
    public:
        XMLHandler(XMLData *data);
        virtual ~XMLHandler();

    private:
        XMLData *_data;
        /* add your private declarations */
};

#endif /* XMLHANDLER_H */
