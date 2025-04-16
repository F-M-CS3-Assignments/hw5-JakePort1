comp: 
	g++ -std=c++11 -Wall -g Graph.cpp GraphTests.cpp -o graph-tests
	g++ -std=c++11 -Wall -g Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests


compAlgo:
	g++ -std=c++11 -Wall BetterPriorityQueue.cpp Dijkstra.cpp Graph.cpp DijkstraTests.cpp -o dijkstra

run: 
	./graph-tests 
	./bpq-tests
	./dijkstra

all: comp run 