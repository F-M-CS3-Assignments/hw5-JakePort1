#include "Dijkstra.h"

#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <vector> 


//TIME COMPLEXITY ANSWER: 



int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){

    //these initialze the queue, as well as the start and end node. 
    BetterPriorityQueue unvisited; 
    set<nodekey_t> visited; //use this to track all nodes that have been visited. 



    BPQNode startNode; 
    startNode.gnode = start; 
    startNode.pri = 0; 

    BPQNode endNode; 
    endNode.gnode = end; 


    //collects all the nodes keys into one set 
    set<nodekey_t> allNodes = g->GetNodes();

    //will iterate through the list of all Nodes, and create a node for each one. It then will push this newly created not to
    //the queue 
    for(auto& nodeKey : allNodes){ 
        BPQNode newNode; 
        newNode.gnode = nodeKey; 
        newNode.pri = ULLONG_MAX;
        unvisited.push(newNode); 
    }

    //This will updatge the queue and set the prioity of the start node (denoted start) to 0;
    unvisited.Update(startNode); 


    //so long as the nodes that are unvisited is not empty, there will still be things to check: 
    while(!unvisited.empty()){



        //Need to visit the node thats the shortest distance away. Start by initialize the current node: 
        BPQNode currNode = unvisited.top(); //gets the node with the lowest distance, which to start is the current node: 
        unvisited.pop(); //takes it out of the queue because we are using it now. 


        // .count() checks if the key exists in the visited nodes set. If it does, then we can skip it. 
        if(visited.count(currNode.gnode)){ 
            continue; 
        }


        //explore all the nodes adjancent to currNode, and keep track of which has the shortest distance. 
        set<const GraphEdge*> adjList = g->GetOutwardEdgesFrom(currNode.gnode);
        for(auto& edge : adjList){ 
            int edgeWeight = edge->weight; 
            int altPathDistance = currNode.pri + edgeWeight; 

            //test to see if the alterantive path is shorter than that current path, do this usuing update()
            BPQNode altPathNode; 
            altPathNode.pri = altPathDistance; 
            altPathNode.gnode = edge->to;
            unvisited.Update(altPathNode); //this will only update if the alternate path is smaller. 
        }
        

        //if its at the same node as the end node, it will return that distanc 
        if (currNode.gnode == end) {
            return currNode.pri;
            }

        //marks the current node as visited
        currNode.visited = true; 
        visited.insert(currNode.gnode); //use this to track whats visited more easily 
    }

    return 0;
};
