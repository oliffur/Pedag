/* finds the maximum path sum from one node to another in a binary tree
 * 
 * uses recursion
 */

#include <iostream>
#include "TreeNode.h"


// returns the maximum path that ends at root, while updating the maximum path
// sum as well
int findMaxSum(TreeNode* root, int& maximum){
	if (!root) return 0;
	
	// recursively find the left and right maximum path sums
	int left = findMaxSum(root->left);
	int right = findMaxSum(root->right);

	// finds the maximum path sum that ends at root
	int curr = max(root->value, root->value + left, root->value + right);
	
	// update the maximum to the max of the current maximum, the root node,
	// and the sum of the root and the left and right paths
	maximum = max(maximum, curr, root->value + left + right);	
	
	// return the max path sum to the root node
	return curr;
}
