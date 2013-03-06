all: SimpleXMLParser

SimpleXMLParser: main.o
	g++ main.o -o build/SimpleXMLParser

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o build/SimpleXMLParser
