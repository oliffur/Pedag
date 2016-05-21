#include <vector>
#include <iostream>

class MatrixGraph extends Graph{
private:
	// adjacency matrix
	vector<vector<int>> m;

public:
	
	// base constructor; no arguments
	MatrixGraph(): m(vector<vector<double>>), size(0){}

	// base constructor with matrix with check for size
	MatrixGraph(vector<vector<double> m): m(m), size(m.size()){
		int size = m.size();
		for (int i = 0; i < m.size(); i++){
			if (m[i].size() != size) throw -1;
		}
	}
	
	// returns number of vertices
	int size();

	void addVertex();
	
	// joins two vertices and adds a weight to the edge
	void joinWithWeight(int v1, int v2, int w);

	void join(int v1, int v2);

	void setWeight(int v1, int v2, int w);
	
	// checks whether two vertices are connected
	bool isNeighbors(int v1, int v2);
	
	// get neighbors for vertex
	vector<int> getNeighbors(int v);

}

int MatrixGraph::size(){
	return m.size();
}

void MatrixGraph::addVertex(){
	for (int i = 0; i < m.size(); i++){
		m[i].push_back(0);
	}
	m.push_back(vector<int>(m.size()+1,0));
}

void MatrixGraph::joinWithWeight(int v1, int v2, int w){
	// no need for simple bounds checks because setWeight performs them

	// check that the edge does not already exist
	if (m[v1][v2]!=0) throw 0;

	// check that the weight to be set is not 0
	if (w==0) throw 0;
	setWeight(v1,v2,w);
}

void MatrixGraph::setWeight(int v1, int v2, int w){
	// bounds check
	if (v1<0 || v2<0) throw -1;
	if (v1>m.size() || v2>m.size()) throw 1;

	// allows you to set w=0! be careful
	m[v1][v2] = w;
	m[v2][v1] = w;
}

void MatrixGraph::join(int v1, int v2){
	joinWithWeight(v1,v2,1);
}

bool MatrixGraph::isNeighbors(int v1, int v2){
	// bounds check
	if (v1<0 || v2<0) throw -1;
	if (v1>=m.size() || v2>=m.size()) throw 1;

	return (m[v1][v2]!=0);
}

vector<int> MatrixGraph::getNeighbors(int v){
	// bounds check
	if (v<0) throw -1;
	if (v>m.size()) throw 1;

	vector<int> neighbors;

	for (int i = 0; i < m.size(); i++){
		if (m[v1][i]!=0) neighbors.push_back(i);
	}

	return neighbors;
}


