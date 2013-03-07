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
#include <string>   // c++  strings
#include <cstring>  // c    strings

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



    FILE    *pFile;
    char    buffer  [1000];
    char    name    [100];

    pFile = fopen ("mephi.xml" , "r");
    if (pFile == NULL) perror("Error opening file");
    else
    {
        while ( !feof(pFile) )
        {
            if ( fgets (buffer , 1000 , pFile) == NULL ) break;

            size_t len = strlen(buffer);
            printf("The len: %d", len);

            for (int i=0; i<len; ++i)
            {
                if (buffer[i] == '"')
                {
                    char *start = &buffer[++i];
                    while (buffer[i] != '"')
                    {
                        ++i;
                    }
                    char *end = &buffer[i];

                    int size = end - start;
                    memcpy(name, start, size);
                    name[size] = '\0';
                    printf(" Bingo!!!!%d: %s\n", strlen(name), name);
                }

            }

            fputs (buffer , stdout);
            //if ( fgetws (wbuffer , 1000 , pFile) == NULL ) break;
            //fputs (buffer , stdout);

        }
    fclose (pFile);
    }

    //wifstream xmlfile(filename);     // read-only by default
    //if ( !xmlfile.is_open() )
    //{
        //cerr << "Unable to open " << filename << endl;
        //return false;
    //}
    //cout << "Begin to parse " << filename << endl;
    //result = true;

    //string line;
    //wstring wc;

    //while (xmlfile.good())
    //{
        ////getline (xmlfile,line);
        ////getline (xmlfile, wc);

        //// parse 'line'

        ////wcout << wc << endl;
        ////unsigned int lineSize = line.size();
        ////for (unsigned int i=0; i < lineSize; ++i)
        //{
            ////cout << line.at(i);

            ////char ch[] = "<";
            ////int cmp = strcmp(&line.at(i), ch);
            ////cout << cmp << "_";


            ////if ( !strcmp(&line.at(i), ch) )        // 0 - strings're equal
            ////{
                ////cout << endl << "< found-----:" << i << endl;
            ////}
        //}
    //}



    //xmlfile.close();
    return result;
}







