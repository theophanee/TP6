CPP=g++ --std=c++11 -Wall

all : Sommet.o test.o 
	$(CPP) -o test test.o Sommet.o

Sommet.o : Sommet.cpp Sommet.hpp
	$(CPP) -c Sommet.cpp

test.o : test.cpp Sommet.hpp
	$(CPP) -c test.cpp

clean :
	rm *.o *.exe