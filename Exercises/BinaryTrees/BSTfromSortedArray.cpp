/* creates a BST from a sorted array recursively
 *
 */

 #include <iostream>
 #include "TreeNode.h"
 #include <vector>

 using namespace std;

// creates a BST between beginning and ending indices and returns the root
TreeNode* createBST(vector<int>& vec, int begIdx, int endIdx){

	// deals with small cases
 	if (begIdx == endIdx) return new TreeNode(vec[begIdx]);
	if (begIdx > endIdx) return nullptr;
	
	// find the middle of begIdx and endIdx and construct a new TreeNode
	int middle = (begIdx + endIdx)/2;
	TreeNode* root = new TreeNode(vec[middle]);
	
	// assign left and right children and also construct BSTs through recursion
	root->left = createBST(vec, begIdx, middle-1);
	root->right = createBST(vec, middle+1, endIdx);
	
	return root;
 }
