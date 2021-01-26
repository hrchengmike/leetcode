all: bst.o 98_valid_bst.o test

bst.o: ../bst.cpp 
	g++ -c $^

98_valid_bst.o: 98_valid_bst.cpp
	g++ -c $^

test: 98_valid_bst.o bst.o
	g++ -o $@ $^