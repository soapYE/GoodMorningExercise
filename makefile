CC = g++
CFLAGS = -Wall -g

UnitTest.out: UnitTest.o URIStatiscalHelper.o
	$(CC) $(CFLAGS) -o UnitTest.out UnitTest.o URIStatiscalHelper.o

UnitTest.o: UnitTest.cpp
	$(CC) $(CFLAGS) -c UnitTest.cpp

URIStatiscalHelper.o: URIStatiscalHelper.cpp URIStatiscalHelper.hpp StatiscalCalculator.hpp
	$(CC) $(CFLAGS) -c URIStatiscalHelper.cpp

clean :
	-rm *.o