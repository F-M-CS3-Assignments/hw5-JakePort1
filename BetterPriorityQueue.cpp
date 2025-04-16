

#include "BetterPriorityQueue.h"
#include <vector> 




//a minimum item will be first (or ahread in prioirty) of a maximum item.

        bool BetterPriorityQueue::Contains(BPQNode node){ 
            for(auto& n : this->c){
                if(node == n){ 
                    return true; //returns true if node is in the vector
                }
            }
            return false; //returns false otherwise. 
        }

        bool BetterPriorityQueue::Update(BPQNode node){ 
            bool isInQueue = false; 

            for(auto& n : this->c){  //iterates through the nodes in the queue
                if(n.gnode == node.gnode){ //will only update the value if the node is in the queue and if its prioirty is lower than before. 
                    if(node.pri < n.pri){ 
                        n.pri = node.pri; 
                        isInQueue = true; 
                        make_heap(this->c.begin(), this->c.end(), this->comp); // this reorganizes the binary heap so that its 
                    }                                                           // not invalid. 
                }
            }
            return isInQueue; 
        }

        string BetterPriorityQueue::ToString(){ 
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


        string BetterPriorityQueue::BPQNodeToString(const BPQNode node){ 
            ostringstream output; //creates an output stream to store string values in 
            output << "(" << node.gnode << ", pri: " << node.pri << ")";
            return output.str(); 
        }
