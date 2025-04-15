comp: 
	g++ -std=c++11 -Wall -g Graph.cpp GraphTests.cpp -o graph-tests

run: 
	./graph-tests 

all: comp run 