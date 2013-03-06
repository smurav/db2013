# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall


all: SimpleXMLParser

SimpleXMLParser: main.o xmlparser.o xmldata.o xmlhandler.o
	mkdir -p build
	$(CC) main.o xmlparser.o xmldata.o xmlhandler.o -o build/SimpleXMLParser
	# build/SimpleXMLParser

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

xmlparser.o: xmlparser.cpp
	$(CC) $(CFLAGS) -c xmlparser.cpp

xmldata.o: xmldata.cpp
	$(CC) $(CFLAGS) -c xmldata.cpp

xmlhandler.o: xmlhandler.cpp
	$(CC) $(CFLAGS) -c xmlhandler.cpp


clean:
	rm -rf *.o build/SimpleXMLParser
