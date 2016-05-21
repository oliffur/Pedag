/* Performs breadth-first search
 *
 * BFS finds the shortest traversal paths in a given graph
 *
 * The predecessor subgraph, or the subgraph of edges traversed by BFS, is the
 * graph of shortest paths from the source to any vertex.
 */

#include "AdjGraph.h"
#include "MatrixGraph.h"
#include <climits>
#include <queue>

using namespace std;

// performs BFS on graph G with source vertex s
void bfs(Graph g, int s, vector<int>& predVec){
	// bounds check
	if (s<0 || s>g.size()) throw -1;
	
	int numVerts = g.size();

	// 'color' of each vertex;
	// -1: unsearched
	// 0:  frontier of vertices being searched (boundary)
	// 1:  searched
	vector<int> colorVec(numVerts,-1);
	
	// distance from s to a vertex; initialized to infinity
	vector<int> distVec(numVerts, INT_MAX);

	// vector of predecessors
	vector<int> predVec(numVerts, -1);
	
	// initialize s into vectors
	colorVec[s] = 0;
	distVec[s] = 0;
	
	// make a queue and enqueue s
	queue<int> q;
	q.push(s);

	// do BFS; continuously remove the frontier from q, and then add all of the
	// vectors neighboring the frontier to the q and process them
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int neib: g.getNeighbors(v)){
			if (colorVec[neib]==-1) {
				colorVec[neib] = 0;
				// process neib
				distVec[neib] =  distVec[v] + 1;
				predVec[neib] = v;
				q.push(neib);
			}
		}
		colorVec[v] = 1;
	}
}

void printPath(Graph g, int v, int v2, vector<int>& predVec){
	if (v2==v) cout << v << endl;
	if (predVec[v2]<0) cout << "no path" << endl;
	else{
		printPath(g,v,predVec[v2],predVec);
		cout << v2 << endl;
	}
}
