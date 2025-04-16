#include "Dijkstra.h"




//TIME COMPLEXITY ANSWER: 



int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){

    //these initialze the queue, as well as the start and end node. 
    BetterPriorityQueue unvisited; 

    BPQNode startNode; 
    startNode.gnode = start; 
    startNode.pri = 0; 


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

        //explore all the nodes adjancent to currNode, and keep track of which has the shortest distance. 




    }





// Step 1, mark all nodes as unvisited
    // a list of full unvisited nodes and emtpy visited nodes

    //have some way of tracking their distances, maybe in the struct?

    //visit adjacent nodes, and update their distance in the struct
    //and have a pointer node in that node pointing to which node it came from, so B(distance = 2, previousnode = A)

    //then go to shortest path and visit that nodes unvisited neighbors, once you visit those neighbors, go and bisit 
    // the rest of the unvisited neighbors of your orignal start node 




    // //---implementation-- 

    // set<nodekey_t> visited; 
    // set<nodekey_t> unvisited = g->GetNodes(); //sets all as unvisited. 

    // //initalize the priority queue: 
    // BetterPriorityQueue queue; 


    // //establish the start node. 
    // BPQNode startNode;
    // startNode.gnode = start;   // Store the start node identifier (key)
    // startNode.distance = 0;    // Distance of the start node is 0
    // startNode.previousNode = nullptr;  //start node doesn't have anything before it . 

    // queue.push(startNode); //push the start node onto the queue. 




    // while(!queue.empty()){
    //     //get pointers to the nodes that the start ponts to
    //     BPQNode currNode = queue.top(); 

    //     set<const GraphEdge*> outwardNodes = g->GetOutwardEdgesFrom(currNode.gnode);


    //     //this will iterate through the list of outgoing edges, and detirmine which one has the lowest weight. It will then 
    //     // save that weight and the nodeKey in the below variables. 
    //     unsigned int edgeWeight = ULLONG_MAX;
    //     nodekey_t nodeKey; 

    //     for(auto& edge : outwardNodes){ 
    //         if(edge->weight < edgeWeight){ 
    //             edgeWeight = edge->weight; //this will set edgeWeight to the smallest option
    //             nodeKey = edge->to;         //this will save the key of that node. 

    //             // //but also you need to create a node for this and add it to the queue; 
    //             // BPQNode* newNode = new BPQNode; 
    //             // newNode->distance = currNode.distance + edge->weight;
    //             // newNode->previousNode = &currNode; //wait i don't think that this is right, it might be setting things when its not supposed to 
    //         }


    //         //this will push the shortest option back onto the queue 
    //         BPQNode* newNode = new BPQNode; 
    //         newNode->gnode = nodeKey; 
    //         newNode-> distance = currNode.distance + edgeWeight; //sets the distance part of the table 
    //         newNode-> previousNode = &currNode; //sets the adress of previousNode to the current node for reference later. May not need. 

    //         queue.push(newNode); 




        
    //     }



    // }

    
    // //set distance of start node as 0; 


    //I think i will have some sort of while(!empty) type thing for iterating 
    

    return 0;
};
