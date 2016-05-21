#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include "TrieNode.h"

using namespace std;

void dfs(vector<vector<char>>& grid, vector<vector<bool>> visited,\
string s, int i, int j, Trie* t);

void findWords(vector<vector<char>>& grid, vector<string>& words){
	Trie* t = new Trie('0');
	for (int i = 0; i < words.size(); i++){
		t->insert(words[i]);
	}

	if (grid.size()==0) return;
	int numRows = grid.size();
	int numCols = grid[0].size();

	vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

	for (int i = 0; i<numRows; i++){
		for (int j = 0; j<numCols; j++){
			dfs(grid,visited,"",i,j,t);
		}
	}
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>> visited,\
string s, int i, int j, Trie* t){

	int numRows = grid.size();
	int rowSize = grid[0].size();

	if (i<0 || j<0 || i>numRows || j>rowSize) return;
	if (visited[i][j]) return;

	s = s + grid[i][j];
	
	if (!t->startsWith(s)) return;
	if (t->search(s)) cout << s << endl;

	visited[i][j] == true;
	dfs(grid, visited, s, i-1, j, t);
	dfs(grid, visited, s, i+1, j, t);
	dfs(grid, visited, s, i, j-1, t);
	dfs(grid, visited, s, i, j+1, t);
	visited[i][j] = false;
	
	return;
}

int main(){
	vector<vector<char>> grid = \
	{
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'}
	};

	vector<string> words = {"oath", "pea", "eat", "rain"};

	findWords(grid, words);
	
	return 0;
}
