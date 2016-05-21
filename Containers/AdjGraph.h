#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class AdjNode{
public:
	// value representing the numbered vertex
	int val;

	// weight
	double w;

	// a pointer to the next neighbor
	AdjNode* next;

	// base constructor with no arguments
	AdjNode(): val(-1), w(0), next(nullptr) {}
	
	// constructor with val
	AdjNode(int val): val(val), w(0), next(nullptr){}
	
	// constructor with val and pointer
	AdjNode(int val, AdjNode* next): val(val), w(0), next(next) {}

	// constructor with all arguments
	AdjNode(int val, double w, AdjNode* next): val(val), w(w), next(next){}
}



class AdjGraph extends Graph{
private:
	// a vector with a space for each vertex
	vector<AdjNode*> vertices;

public:
	
	// constructor with no arguments
	AdjGraph(): vertices(vector<adjNode>){}
	
	// get number of vertices
	int size();

	// add vertex
	void addVertex();

	// add vertex with adjacency list
	void addVertex(AdjNode* node);
	
	// joins two vertices with an edge without checking if edge already exists
	void joinNoCheck(int v1, int v2);

	// joins two vertices while checking if edge already exists
	void join(int v1, int v2);
	
	// checks if two vertices are connected
	bool isNeighbors(int v1, int v2);

	// get neighbors for point
	vector<int> getNeighbors(int v);


}

int AdjGraph::size(){
	return vertices.size();
}

void AdjGraph::addVertex(){
	vertices.push_back(nullptr);
}

void AdjGraph::addVertex(AdjNode* node){
	vertices.push_back(node);
}

void AdjGraph::joinNoCheck(int v1, int v2){
	// check bounds
	if (v1<0||v2<0) throw -1;
	if (v1>=vertices.size()||v2>=vertices.size()) throw 1;
	
	AdjNode one = new AdjNode(v1,vertices[v2]);
	AdjNode two = new AdjNode(v2, vertices[v1]);

	vertices[v1] = &two;
	vertices[v2] = &one;

	return;
}

void AdjGraph::join(int v1, int v2){
	// check bounds
	if (v1<0||v2<0) throw -1;
	if (v1>=vertices.size()||v2>=vertices.size()) throw 1;

	AdjNode* curr = vertices[v1];
	while (curr){
		if (curr->val = v2) throw 2;
		curr = curr->next;
	}

	joinNoCheck(v1,v2);

	return;
}

bool AdjGraph::isNeighbors(int v1, int v2){
	// check bounds
	if (v1<0||v2<0) throw -1;
	if (v1>=vertices.size()||v2>=vertices.size()) throw 1;

	AdjNode* curr = vertices[v1];

	while (curr){
		if (curr->val == v2) return true;
	}

	return false;
}



vector<int> AdjGraph::getNeighbors(int v){
	// check that vertexNum is within bounds
	if (v<0) throw -1;
	if (v>=vertices.size()) throw 1;
	
	// create a vector and push all neighbors of vertex into it
	vector<int> neighbors;

	AdjNode* curr = vertices[v];
	while (curr){
		neighbors.push_back(curr->val);
		curr = curr->next;
	}

	return neighbors;
}



