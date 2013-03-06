all: SimpleXMLParser

SimpleXMLParser: main.o xmlparser.o xmldata.o
	mkdir -p build
	g++ main.o -o build/SimpleXMLParser
	# build/SimpleXMLParser

main.o: main.cpp
	g++ -c main.cpp

xmlparser.o: xmlparser.cpp
	g++ -c xmlparser.cpp

xmldata.o: xmldata.cpp
	g++ -c xmldata.cpp

clean:
	rm -rf *.o build/SimpleXMLParser
