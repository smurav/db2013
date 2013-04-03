#!/bin/bash

# Compile official example

gcc -I/usr/include/libxml2 -lxml2 official_xpath_exml.c -o xpath_it
