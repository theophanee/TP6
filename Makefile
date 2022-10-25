CPP=g++ --std=c++11 -Wall

all : test arete sommet graphe

Sommet.o : Sommet.cpp Sommet.hpp
	$(CPP) -c Sommet.cpp

Arete.o : Arete.cpp Arete.hpp
	$(CPP) -c Arete.cpp

Graphe.o : Graphe.cpp Graphe.hpp
	$(CPP) -c Graphe.cpp

test.o : test.cpp Sommet.hpp Arete.hpp Graphe.hpp
	$(CPP) -c test.cpp

test : Sommet.o Arete.o Graphe.o test.o 
	$(CPP) -o test test.o Sommet.o Arete.o Graphe.o

test_arete.o : test_arete.cpp Sommet.hpp Arete.hpp
	$(CPP) -c test_arete.cpp

arete : Sommet.o Arete.o test_arete.o 
	$(CPP) -o arete test_arete.o Sommet.o Arete.o

test_sommet.o : test_sommet.cpp Sommet.hpp
	$(CPP) -c test_sommet.cpp

sommet : Sommet.o test_sommet.o
	$(CPP) -o sommet test_sommet.o Sommet.o 

test_graphe.o : test_graphe.cpp Sommet.hpp Arete.hpp Graphe.hpp
	$(CPP) -c test_graphe.cpp

graphe : Sommet.o Arete.o Graphe.o test_graphe.o 
	$(CPP) -o graphe test_graphe.o Sommet.o Arete.o Graphe.o

clean :
	rm *.o *.exe