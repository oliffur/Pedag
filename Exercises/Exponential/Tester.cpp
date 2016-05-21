#include <iostream>
#include "Permutations.cpp"
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main(){
	vector<int> vec = {1,1,2,4,4,4};
	set<vector<int>> mySet = permute(vec);
	for(auto itr = mySet.begin(); itr != mySet.end(); ++itr){
		copy((*itr).begin(), (*itr).end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
