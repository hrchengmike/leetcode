all: bst.o main.o test

bst.o: ../bst.cpp 
	g++ -c $^

main.o: main.cpp
	g++ -c $^

test: main.o bst.o
	g++ -o $@ $^