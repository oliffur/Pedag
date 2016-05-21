#include <vector>
#include <iostream>

using namespace std;

// returns a vector of pointers to head nodes of all BSTs constructed of
// elements in [begIdx, endIdx]
vector<TreeNode*> generateTrees(int begIdx, int endIdx){
	vector<TreeNode*> headList = new vector<TreeNode*>(nullptr);
	
	// if the beginning index is before the ending index, return a vector with
	// only a null pointer in it
	if (begIdx>endIdx){
		headList.insert(nullptr);
		return headList;
	}

	// loop through i, finding all trees whose root is i and whose other
	// elements are within [begIdx, endIdx]
	for (int i = begIdx; i <= endIdx; i++){
		// recursively find the respective BSTs for elements smaller than i 
		// and elements greater than i
		vector<TreeNode*> lefts = generateTrees(begIdx, i-1);
		vector<TreeNode*> rights = generateTrees(i+1, end);
		
		// loop through and piece them together
		for (int j = 0; j < lefts.size(); j++){
			for (int k = 0; k < rights.size(); k++){
				TreeNode* node = new TreeNode(i);
				node->left = lefts[j];
				node->right = rights[k];
				headList.add(node);
			}
		}
	}

	return headList;
}
