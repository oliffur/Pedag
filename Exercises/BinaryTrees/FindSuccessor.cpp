/* finds the successor to a TreeNode
 *
 */

#include <iostream>
#include "TreeNode.h"

TreeNode* successor(TreeNode* curr){
	if (curr->right){
		TreeNode* temp = curr->right;
		while (temp->right) temp = temp->right;
		return temp;
	}

	if (!curr->parent) return nullptr;

	if (curr->parent->left == curr) return curr->parent;
	if (curr->parent->right == curr){
		TreeNode* temp = curr->parent;
		while (temp->parent && temp->parent->right==temp) temp = temp->parent;
		return !temp->parent ? nullptr : temp->parent;
	}
}
