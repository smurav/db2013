/*
 * xmldata.h
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

/* This class store some Data from XML file,
 * like map <int, DataNode>
 */

#ifndef XMLDATA_H
#define XMLDATA_H

#include <map>

/* Struct contain all nessesary info about one xml-tag
 */
struct DataNode
{
    int id;
};

class XMLData
{
    public:
        XMLData();
        ~XMLData();

    private:
        std::map<unsigned int, DataNode> _data;
};

#endif /* XMLDATA_H */
