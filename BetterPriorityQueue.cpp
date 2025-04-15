
#include <queue> 
#include <vector> 
#include "Graph.h"
#include <sstream>


using namespace std; 

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


//a minimum item will be first (or ahread in prioirty) of a maximum item.
class BetterPriorityQueue: public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>> {


    public:
        bool contains(BPQNode node){ 
            for(auto& n : this->c){
                if(node == n){ 
                    return true; //returns true if node is in the vector
                }
            }
            return false; //returns false otherwise. 
        }

        bool update(BPQNode node){ 
            bool isInQueue = false; 

            for(auto& n : this->c){  //iterates through the nodes in the que 
                if(n == node){ //will only update the value if the node is in the queue and if its prioirty is lower than before. 
                    if(node.pri < n.pri){ 
                        n.pri = node.pri; 
                        isInQueue = true; 
                    }
                }
            }
            return isInQueue; 
        }

        string ToString(){ 
            ostringstream output; //creates an output stream to store string values in 

            output << "["; //strats the bracket for formatting 

            for(int i = 0; i < this->c.size(); i++){ 
                if(i == this->c.size() - 1){ //don't add comma to the last one, and include closing bracket. 
                    output << BPQNodeToString(this->c.at(i)) << ']';
                }else{
                output << BPQNodeToString(this->c.at(i))<< ", "; //adds a comma after each item 
                }
            }
            return output.str(); //returns the string version of the output stream 
        }

        
        static string BPQNodeToString(BPQNode node){ 
            ostringstream output; //creates an output stream to store string values in 
            output << "(" << node.gnode << ", pri: " << node.pri << ")";
            return output.str(); 
        }


};