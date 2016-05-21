#include <iostream>
#include <vector>
#include <set>

using namespace std;

void swap(vector<int>& vec, int idxOne, int idxTwo){
	int temp = vec[idxOne];
	vec[idxOne] = vec[idxTwo];
	vec[idxTwo] = temp;
}

void permuteUnique(vector<int>& vec, int begIdx, set<vector<int>>& mySet){
	
	if (begIdx == vec.size()){
		mySet.insert(vec);
		return;
	}

	for (int i = begIdx; i < vec.size(); i++){
		swap(vec, begIdx, i);
		permuteUnique(vec, begIdx+1, mySet);
		swap(vec, begIdx, i);
	}
}

set<vector<int>> permute(vector<int>& vec){
	set<vector<int>> mySet;
	permuteUnique(vec, 0, mySet);
	return mySet;
}

