
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	g->AddNode(4);
	g->AddNode(5);
	g->AddNode(6);
	
	g->AddEdge(1, 2, 7);
	g->AddEdge(2, 1, 7);
	g->AddEdge(1, 3, 9);
	g->AddEdge(3, 1, 9);
	g->AddEdge(1, 6, 14);
	g->AddEdge(6, 1, 14);
	
	g->AddEdge(2, 3, 10);
	g->AddEdge(3, 2, 10);
	g->AddEdge(2, 4, 15);
	g->AddEdge(4, 2, 15);
	
	g->AddEdge(3, 6, 2);
	g->AddEdge(6, 3, 2);
	g->AddEdge(3, 4, 11);
	g->AddEdge(4, 3, 11);
	
	g->AddEdge(6, 5, 9);
	g->AddEdge(5, 6, 9);
	
	g->AddEdge(4, 5, 6);
	g->AddEdge(5, 4, 6);
	
	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 5;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 20);

	delete g;
	
	cout << "DONE Testing Dijkstra Algorithm" << endl;
	
	return ans;
}


void MoreDijkstraTests(){
	cout << "Deep Testing Dijkstra Algorithm..." << endl;

	// Your code goes here!

	Graph *graph1 = new Graph();
	
	graph1->AddNode(1);
	graph1->AddNode(3);
	graph1->AddNode(4);
	graph1->AddNode(9);

	graph1->AddEdge(3, 1, 3);
	graph1->AddEdge(3, 4, 8);
	graph1->AddEdge(3, 9, 2);
	graph1->AddEdge(1, 4, 1);
	graph1->AddEdge(4, 9, 5);

	int answer = 4; 
	int result = dijkstra(3,4,graph1);

	assert(answer == result ); 

	Graph *graph2 = new Graph; 
	graph2->AddNode(1);
	graph2->AddNode(2);
	graph2->AddNode(3);
	graph2->AddNode(4);


	graph2->AddEdge(1, 2, 2223);
	graph2->AddEdge(2, 3, 333333);
	graph2->AddEdge(3, 4, 999999);
	graph2->AddEdge(1,4,1); 

	assert(dijkstra(1,4,graph2)== 1); 
	

	cout << "new tests passed";
















	cout << "DONE Deep Testing Dijkstra Algorithm" << endl;
}


int main(){
	
	DijkstraTest(); // this one by itself tests the graph on the assignment
	cout << endl;
	MoreDijkstraTests();
	cout << endl;
	cout << "ALL TESTS PASSED!" << endl;

	return 0;
}
