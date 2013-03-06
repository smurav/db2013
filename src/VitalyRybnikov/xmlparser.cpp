/*
 * xmlparser.cpp
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
 *
 */


#include "xmlparser.h"

#include <iostream>
#include <fstream>
using namespace std;


XMLParser::XMLParser()
{
        cout << "Create xml-parser obj" << endl << endl;
}

XMLParser::~XMLParser()
{
        cout << "Remove xml-parser obj" << endl << endl;
}

//------------------------------------------------------------------------------
bool XMLParser::parse(XMLHandler *handler, char *filename)
{
    bool result = false;

    if (!handler)       // we have bad pointer
        return false;



    ofstream xmlfile;
    xmlfile.open(filename, ios::in);
    if (!xmlfile.is_open())
    {
        cerr << "Error occurs while try to Open " << filename << endl;
        return false;
    }
    cout << "Begin to parse " << filename << endl;
    result = true;




    xmlfile.close();
    return result;
}







