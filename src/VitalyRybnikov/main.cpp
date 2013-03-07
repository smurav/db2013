/*
 * main.cpp
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

/* This is Simple XML Parser
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
//------------------------------------------------------------------------------
#include "xmldata.h"
#include "xmlhandler.h"
#include "xmlparser.h"

using namespace std;

void help(char *programName);
//------------------------------------------------------------------------------



int main(int argc, char **argv)
{
    if (argc < 2)       // program started without any args
        help(argv[0]);


    // Initialize main objects
    XMLData     *xmlData    = new XMLData();
    XMLHandler  *xmlHandler = new XMLHandler(xmlData);
    XMLParser   xmlParser;

    if (xmlParser.parse(xmlHandler, argv[1]))
    {
        // data.print();
    } else {
        // some error occurs...
        //cout << "Some errors occured" << endl;
    }



    // Clear memory
    cout << endl;
    delete xmlHandler;
    delete xmlData;
    return 0;
}


void help(char *programName)
{
    cout << "Using: " << programName << " <path_to_XML_file.xml>" << endl;
    exit(-1);
}
