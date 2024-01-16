CC = g++
CFLAGS = -Wall -g

UnitTest.out: UnitTest.o URIStatiscalHelper.o StatiscalRequest.o Request.o
	$(CC) $(CFLAGS) -o UnitTest.out UnitTest.o URIStatiscalHelper.o StatiscalRequest.o Request.o

UnitTest.o: UnitTest.cpp
	$(CC) $(CFLAGS) -c UnitTest.cpp

URIStatiscalHelper.o: URIStatiscalHelper.cpp URIStatiscalHelper.hpp StatiscalCalculator.hpp
	$(CC) $(CFLAGS) -c URIStatiscalHelper.cpp

StatiscalRequest.o: Request.hpp Request.cpp StatiscalRequest.hpp StatiscalRequest.cpp
	$(CC) $(CFLAGS) -c StatiscalRequest.cpp

Request.o: Request.hpp Request.cpp
	$(CC) $(CFLAGS) -c Request.cpp

clean :
	-rm *.o