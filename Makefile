all: hw2.cpp
	g++ -g -Wall -o hw2 hw2.cpp -larmadillo -lmlpack -fopenmp
