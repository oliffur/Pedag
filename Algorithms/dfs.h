/* Performs depth-first search
 *
 * DFS goes deeply in one direction first and then backtracks to search for
 * more nodes.
 *
 * The predecessor subgraph is a group of trees
 */

#include "Graph.h"

void dfs(Graph g, int s, vector<int> predVec){
	// bounds check
	if (s<0 || s>g.size()) throw -1;

	int numVerts = g.size();

	// 'color' of each vertex;
	// -1: unsearched
	// 0: frontier
	// 1: searched
	vector<int> colorVec(numVerts,-1);

	// discovery time
	vector<int> discVec(numVerts, 0);

	// finishing time
	vector<int> finVec(numVerts, 0);
	
	int time = 0;

	dfsVisit(g, s, predVec, time);
}

void dfsVisit(Graph& g, int v, vector<int>& predVec, int& time, \
  vector<int> discVec, vector<int> finVec){
	time++;
	discVec[v] = time;
	colorVec[v] = 0;

	for (int neib: g.getNeighbors(v)){
		if (color[neib]==-1){
			//process neib
			predVec[neib] = v;
			dfsVisit(g, neib, predVec, time);
		}
	}

	colorVec[v] = 1;
	time++;
	finVec[v] = time;
}

/* the interval of discovery/finish times [dis[v], fin[v]] satisfy the
 * parentheses property (no two intervals cross).
 *
 * If [dis[v],fin[v]] is contained within [dis[v2],fin[v2]] then v is a
 * descencent of v2 in the predecessor subgraph.
 *
 * for v, v2, v is a descendent of v2 iff at the time of v2's discovery, there
 * is a path from v2 to v consisting entirely of white vertices.
 *
 * Define the following edges:
 * -- Tree Edges  : edges in the DFS predecessor graph
 * -- Back Edges  : edges from v to its ancestor v2
 * -- Fwd Edges   : edges from v to child v2
 * -- Cross Edges : all other edges
 *
 * When e = (v,v2) is furst explored, if the color of v2 is...
 * -- WHITE : e is a tree edge
 * -- GRAY  : e is a back edge
 * -- BLACK : e is a foward/cross edge
 *
 * To determine if a graph is singly connected, run a DFS, if no vertex is
 * visited twice then it is singly connected.
 */

