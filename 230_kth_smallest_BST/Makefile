all: bst.o 230_kth_smallest_BST.o test

bst.o: ../bst.cpp ../bst.h
	g++ -c ../bst.cpp

230_kth_smallest_BST.o: 230_kth_smallest_BST.cpp
	g++ -c 230_kth_smallest_BST.cpp

test: 230_kth_smallest_BST.o bst.o
	g++ -o test 230_kth_smallest_BST.o bst.o 