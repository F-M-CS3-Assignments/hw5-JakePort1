
#include "Graph.h"
#include <iostream>
#include <vector>


using namespace std;


// This method is not part of the Graph class / header on purpose
const GraphEdge* findExistingEdge(nodekey_t gnFrom, nodekey_t gnTo, vector<vector<GraphEdge *>> adjList)
{
	if(adjList.size() == 0)
	{
		return nullptr;  //returns nullptr if there is nothign int he graph 
	}


	for(size_t rowIDX = 0; rowIDX < adjList.size(); rowIDX++)
	{
		vector<GraphEdge*> row = adjList.at(rowIDX);
		for(size_t i = 0; i < row.size(); i++)
		{
			GraphEdge *cur = row.at(i);

			// It might make sense for there to be an == operator overload in the GraphEdge struct
			// but adding methods to a struct feels so _wrong_ to me! ?????

			if(cur->from == gnFrom && cur->to == gnTo)
			{
				return cur;
			}
		}
	} 

	return nullptr;
}


// This method is not part of the Graph class / header on purpose
// This should probably be a method in the GraphEdge struct
// but adding methods to a struct feels so _wrong_ to me!
string GraphEdgeToString(const GraphEdge* e)
{
	return "((" + to_string(e->from) + ")->(" + to_string(e->to) + ") w:" + to_string(e->weight) + ")";
}





void Graph::AddNode(nodekey_t key)
{

	if(this->IsPresent(key))
	{
		throw invalid_argument("Duplicate node cannot be added: " + to_string(key));
	}


	nodes.push_back(key);
	vector <GraphEdge*> *newRow = new vector<GraphEdge*>;
	adjList.push_back(*newRow);
	delete newRow; 
}

 


const GraphEdge *Graph::AddEdge(nodekey_t gnFrom, nodekey_t gnTo, unsigned int w)
{

	// The AddEdge method creates new edges.  It does not and should not update / change
	// the weights of existing edges.  findExistingEdge does not check the weight for this reason
	const GraphEdge* dup = findExistingEdge(gnFrom, gnTo, this->adjList);
	if(dup != nullptr)
	{
		throw invalid_argument("Duplicate edge cannot be added: " + GraphEdgeToString(dup));
	}

	if(!this->IsPresent(gnFrom))
	{
		throw invalid_argument("No such node: " + to_string(gnFrom));
	}

	if(!this->IsPresent(gnTo))
	{
		throw invalid_argument("No such node: " + to_string(gnTo));
	}

	GraphEdge *ge = new GraphEdge{gnFrom,gnTo,w}; //changed to include the arguments set above, i think this is all it needs

	//find the index of the from vector, using find() from 
	//https://stackoverflow.com/questions/15099707/how-to-get-position-of-a-certain-element-in-strings-vector-to-use-it-as-an-inde
	auto it = find(nodes.begin(), nodes.end(), gnFrom);
	size_t fromIndex = distance(nodes.begin(), it);

	adjList.at(fromIndex).push_back(ge); // will add the edge to the vector corresponding to the right key (node).

	// TODO:
	// Do stuff here?  IDK what though
	const GraphEdge *response = ge; // this helps the compiler go
	return response;
}


bool Graph::IsPresent(nodekey_t key) const
{
	// TODO:
	// iterate through this->nodes and look for one that matches key

	for(nodekey_t testKey : this->nodes){ 
		if(testKey == key){  //will return true if the key is found in the list of all nodes 
			return true; 
		}
	}

	return false; 
}




set<const GraphEdge*> Graph::GetOutwardEdgesFrom(nodekey_t node) const 
{
	size_t idx = 0;
	while(idx < this->nodes.size() && (this->nodes.at(idx) != node))
	{
		idx++;
	}
	if(idx == this->nodes.size()){
		throw invalid_argument("No such node: " + to_string(node));
	}

	set<const GraphEdge*> result = set<const GraphEdge*>();
	// TODO:
	// iterate over this->adjList.at(idx); and find nodes that match the given node
	// in their "from" field, put those nodes in result
	
	//this will find all the outghoing edges for the given node at index idx, and push back the outwardd connections. 
	for(GraphEdge *const edge : adjList.at(idx)){
		result.insert(edge);
	}
	return result;
}




 set<nodekey_t> Graph::GetNodes() const 
{
	// TODO:
	// iterate of this->nodes, accumulate into a set<nodekey_t> and return it
	set<nodekey_t> setOfNodes; 
	for(nodekey_t node : this->nodes){ 
		setOfNodes.insert(node); 
	}
	return setOfNodes;
}




size_t Graph::Order() const 
{
	return nodes.size();
}

size_t Graph::Size() const 
{
	size_t total = 0;
	for(size_t i = 0; i < adjList.size(); i++){
		vector<GraphEdge*> row = adjList.at(i);
		for(size_t j = 0; j < row.size(); j++){
			total++;
		}
	}

	return total;
}



string Graph::NodesToString() const 
{
	if(nodes.size() == 0)
	{
		return "[]";
	}

	string str = "[";
	for(size_t i = 0; i < (nodes.size() - 1); i++)
	{
		str = str + "(" + to_string(nodes.at(i)) + "), ";
	}

	str = str + "(" + to_string(nodes.at(nodes.size()-1)) + ")]";
	return str;
}

string Graph::EdgesToString() const 
{
	if(this->adjList.size() == 0)
	{
		return "[]";
	}

	size_t count = 0;
	string str = "[";
	for(size_t rowIDX = 0; rowIDX < this->adjList.size(); rowIDX++)
	{
		vector<GraphEdge*> row = this->adjList.at(rowIDX);
		for(size_t i = 0; i < row.size(); i++)
		{
			GraphEdge *cur = row.at(i);
			str = str + GraphEdgeToString(cur);

			if(count < (this->Size() - 1)){
				 str = str + ", ";
			}
			count++;
		}
	} 

	str = str +  "]";
	return str;

}



Graph::~Graph() {
	// TODO:
	// Right now the memory leaks are bad, I need to
	// implement something here to fix it
	//changed this to auto instead of vector<nodekey_t> and it works, not sure why.
	for(auto& vec : adjList){ 
		for(GraphEdge* edge : vec){ 
			delete edge;
		}
		vec.clear(); 
	}
	adjList.clear();  //gets rid of adjList and nodes. 
	nodes.clear(); 
}

