CPP=g++ --std=c++11 -Wall

all : test arete sommet graphe

Sommet.o : Sommet.cpp Sommet.hpp
	$(CPP) -c Sommet.cpp

Arete.o : Arete.cpp Arete.hpp
	$(CPP) -c Arete.cpp

GC.o : GC.cpp GC.hpp
	$(CPP) -c GC.cpp

Graphe.o : Graphe.cpp Graphe.hpp
	$(CPP) -c Graphe.cpp

test.o : test.cpp Sommet.hpp Arete.hpp Graphe.hpp GC.hpp
	$(CPP) -c test.cpp

test : Sommet.o Arete.o Graphe.o test.o GC.o
	$(CPP) -o test test.o Sommet.o Arete.o Graphe.o GC.o

test_arete.o : test_arete.cpp Sommet.hpp Arete.hpp GC.hpp
	$(CPP) -c test_arete.cpp

arete : Sommet.o Arete.o test_arete.o GC.o
	$(CPP) -o arete test_arete.o Sommet.o Arete.o GC.o

test_sommet.o : test_sommet.cpp Sommet.hpp GC.hpp
	$(CPP) -c test_sommet.cpp

sommet : Sommet.o test_sommet.o GC.o
	$(CPP) -o sommet test_sommet.o Sommet.o  GC.o

test_graphe.o : test_graphe.cpp Sommet.hpp Arete.hpp Graphe.hpp GC.hpp
	$(CPP) -c test_graphe.cpp

graphe : Sommet.o Arete.o Graphe.o test_graphe.o  GC.o
	$(CPP) -o graphe test_graphe.o Sommet.o Arete.o Graphe.o GC.o

clean :
	rm *.o *.exe