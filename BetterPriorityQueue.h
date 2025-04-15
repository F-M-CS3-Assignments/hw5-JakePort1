
#ifndef BETTERPRIORITYQUEUE_h
#define BETTERPRIORITYQUEUE_h


#include <queue>
#include <vector>
#include <sstream>
#include "Graph.h"

using namespace std; 

//this was the code given in the .txt file. 
struct BPQNode {
	int pri = INT_MAX;
	bool visited = false;
	nodekey_t gnode = INVALID_NODE_KEY;
	
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