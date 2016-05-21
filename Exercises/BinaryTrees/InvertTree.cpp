#include <iostream>
#include "TreeNode.h"


using namespace std;

void invert(TreeNode* root){
	if (root!=null){
		// swap left and right children of root
		TreeNode* temp = root->left;
		root->left = root->right
		root->right = temp;
		
		// recurse
		if (root->left != nullptr) invert(root->left);
		if (root->right != nullptr) invert(root->right);
	}
}
