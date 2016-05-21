#include <vector>

class Graph{
public:
	int size() = 0;

	void addVertex() = 0;

	void join(int v1, int v2) = 0;

	bool isNeighbors(int v1, int v2) = 0;

	vector<int> getNeighbors(int v);
}
