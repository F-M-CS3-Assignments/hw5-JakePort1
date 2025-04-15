comp: 
	g++ -std=c++11 -Wall -g Graph.cpp GraphTests.cpp -o graph-tests
	g++ -std=c++11 -Wall -g Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests

run: 
	./graph-tests 
	./bpq-tests

all: comp run 