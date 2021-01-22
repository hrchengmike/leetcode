all: bst.o main.o test

bst.o: ../bst.cpp ../bst.h
	g++ -c ../bst.cpp

main.o: main.cpp
	g++ -c main.cpp

test: main.o bst.o
	g++ -o test main.o bst.o 

