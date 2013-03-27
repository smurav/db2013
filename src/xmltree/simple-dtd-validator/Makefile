LIB_XML_DIR = /usr/include/libxml2
TEMP = ../../../temp

all:
	gcc -I$(LIB_XML_DIR) -lxml2 -o $(TEMP)/validate-xml-dtd reader2.c

clean:
	rm -rf $(TEMP)/validate-xml-dtd