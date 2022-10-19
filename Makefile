CPP=g++ --std=c++11 -Wall

all : Sommet.o Arete.o Graphe.o test.o 
	$(CPP) -o test test.o Sommet.o Arete.o Graphe.o

Sommet.o : Sommet.cpp Sommet.hpp
	$(CPP) -c Sommet.cpp

Arete.o : Arete.cpp Arete.hpp
	$(CPP) -c Arete.cpp

Graphe.o : Graphe.cpp Graphe.hpp
	$(CPP) -c Graphe.cpp

test.o : test.cpp Sommet.hpp Arete.hpp Graphe.hpp
	$(CPP) -c test.cpp

clean :
	rm *.o *.exe