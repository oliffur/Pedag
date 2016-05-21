/* traverses a binary tree in three different orders using two different
 * techniques
 *
 */

#include <iostream>
#include <stack>
#include <iterator>
#include "TreeNode.h"

using namespace std;

// preorder traverse the tree recursively
void preorderRecursive(TreeNode* root){

	// first print out the value of the root
	// this implies the root of the tree will be printed first
    cout << root->value << endl;

	// if the left child exists, recurse left
    if (root->left) preorderTraversalRecursive(root->left);
    
	// if the right child exists, recurse right
	// this means that the rightmost node will be printed last
    if (root->right) preorderTraversalRecursive(root->right);
}

// inorder traverse the tree recursively
void inorderRecursive(TreeNode* root){
	
	// if left child exists, recurse left
	// this means that the leftmost node will be printed first
    if (root->left) recursiveIn(root->left);
    
	// print out the value of the root
    cout << root->value << endl;

	// if the right child exists, recurse right
	// this implies the rightmost node will be printed last
    if (root->right) recursiveIn(root->right);
}

// postorder traverse the tree recursively
void postorderRecursive(TreeNode* root){
	// if the left child exists, recurse left
	// this implies the left-most node is printed first
    if (root->left) recursivePost(root->left);
	
	// if the right child exists, recurse right
    if (root->right) recursivePost(root->right);
	
	// print out the value at the root
	// this implies that the root of the tree is printed last
    cout << root->value << endl;
}

// preorder traverses the tree iteratively
void preorderIterative(TreeNode* root){
	
	// create a stack on which to push addresses of nodes that we have not yet
	// processed; generally, this stack will consist of some left child being
	// on the top, followed by its parent's right child, followed by its
	// parent's parent's right child, etc., which matches the hierarchy of
	// printing in a preorder manner
	stack<TreeNode*> TreeStack;

	// address of the current node
    TreeNode* current;

    TreeStack.push(root);
	
	// while TreeStack is not empty...
    while (!TreeStack.empty()){
		
		// pop the top item on the stock and print its value
        current = TreeStack.top();
        TreeStack.pop();
        cout << current->value << endl;

		// if right child of top item exists, push it onto the stack; then do
		// the same for the left child
        if (current->right) TreeStack.push(current->right);
        if (current->left) TreeStack.push(current->left);
    }
}

// inorder traverses the tree iteratively
void inorderIterative(TreeNode* root){

	// set up stack and set 'current' to root
	// current will be the node currently under examination; the stack will
	// hold its parents
    stack<TreeNode*> TreeStack;
    TreeNode* current = root;
    
    while (!TreeStack.empty() || current){
        // if 'current' exists, push current node and continue left
        if (current){
            TreeStack.push(current);
            current = current->left;
        }

        // otherwise, process the current node and go right
        else{
            current = TreeStack.top();
            TreeStack.pop();
            cout << current->value << endl;
            current = current->right;
        }
    }
}

// postorder traverses the tree iteratively
void iterativePost(TreeNode* root){
	// create stack and set current to root
    stack<TreeNode*> TreeStack;
    TreeNode* current = root;
    
	do{
		// move all the way to the left, pushing the right node and the current
		// node of nodes we pass along the way
		//
		// we are not processing the nodes in the order that they will be printed;
		// this is because we pushed the nodes onto the stack in such a way that
		// when we get to a node, we can distinguish whether it is a parent node
		// or a right node; then when we process we will flip them to print them
		// in the correct order
	    while (current){
	        if (current->right) TreeStack.push(current->right);
			TreeStack.push(current);
	        current = current->left;
	    }
	
		// pop from TreeStack and set as current
		current = TreeStack.top();
		TreeStack.pop();
	
		// here: if current node has a right child equal to the node at the top
		// of the stack, then it must be that, in the sequence of visiting the
		// subtrees in a postorder fashion, we have just finished some left
		// branch and we are now looking at the remaining two (parent and right).
		// In this situation, we want to process the right child first, so we flip
		// the nodes to process them
	    if (current->right && TreeStack.top() == current->right){
			TreeStack.pop();
			TreeStack.push(current);
			current = current->right;
		}
		// if the current node has a right child but it is not equal to the top,
		// then it must be that we have just finished a right branch and we are
		// back at the parent;
		// therefore we must print this out
		//
		// if the current node does not have a right child, then we must process
		// this node
		else{
			cout << current->value << endl;
			current = nullptr;
	    }
	}while(!TreeStack.empty());
}

