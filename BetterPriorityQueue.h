
#ifndef BETTERPRIORITYQUEUE_h
#define BETTERPRIORITYQUEUE_h


#include <queue>
#include <vector>
#include <sstream>
#include "Graph.h"

using namespace std; 

//this was the code given in the .txt file. 
struct BPQNode {
    unsigned long long pri = ULLONG_MAX;
	bool visited = false;
	nodekey_t gnode = INVALID_NODE_KEY;
    //maybe add distance here, with it initalized at MAX INT, or 0 for start node.
    BPQNode* previousNode = nullptr; //will use this to refer to the last node; 
    int distance = ULLONG_MAX; //representativce of infinity: 


	
	bool operator<(const BPQNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const BPQNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const BPQNode &other) const {
		return this->gnode == other.gnode;
	}
};


class BetterPriorityQueue: public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>> {

public: 
    bool Contains(BPQNode node); 

    bool Update(BPQNode node);

    string ToString(); 

    static string BPQNodeToString(BPQNode node);

};

#endif