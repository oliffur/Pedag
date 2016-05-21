/* returns a vector of vectors that represents the levels of the tree printed
 * in consecutive order; for example,
 *
 *     3
 *    / \
 *   9  20
 *     / \
 *   15  7
 * 
 * would translate to [[3],[9,20],[15,7]]
 *	
 * also implements a method that finds the minimum depth of a binary tree,
 * using similar concepts
 */

#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

// traverses the tree and prints out the level representation
void levelTraversal(TreeNode* head){
    queue<TreeNode*> TreeQueue;
    TreeQueue.emplace(head);
    
    // a pointer to keep track of the popped pointers from the queue
    TreeNode* currPtr;
    
    // after each iteration, check if the queue is empty; the queue will only
    // be empty if there were no nodes in the next level; at which point the
    // entire tree has been traversed
    while(TreeQueue.size()>0){
        cout << "[";
        // save the current queue size, which represents the number of nodes
        // in the level which had just been examined
        int queueSize = TreeQueue.size();
        // iterate through the queue currently, up to that point
        for (int i = 0; i<queueSize; i++){
            // deQueue the front element and save it
            currPtr = TreeQueue.front();
            TreeQueue.pop();
            // enQueue the left and right children if they exist
            if (currPtr->left) TreeQueue.emplace(currPtr->left);
            if (currPtr->right) TreeQueue.emplace(currPtr->right);
            cout << currPtr->value << ",";
        }
        cout << "], ";   
    }  
}

int minDepth(TreeNode* root){
	// small cases
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	
	// count for how many full layers the tree has
	int count = 1;

    queue<TreeNode*> TreeQueue;
	TreeQueue.emplace(root);
	
	TreeNode* currPtr;

	while (!TreeQueue.empty()){
		int TreeQueueSize = TreeQueue.size()
		for (int i = 0; i<TreeQueueSize; i++){
			currPtr = TreeQueue.top();
            TreeQueue.pop();
			
			// return the count if either the left or right pointer is missing
			if (!currPtr->left || !currPtr->right) return count;
            TreeQueue.emplace(currPtr->left);
            TreeQueue.emplace(currPtr->right);
        }
		count++;
	}
}


int main(){
    TreeNode one(1);
    TreeNode three(3);
    TreeNode four(4);
    TreeNode six(6);
    TreeNode seven(7);
    TreeNode eight(8);
    TreeNode ten(10);
    TreeNode thirteen(13);
    TreeNode fourteen(14);
    
    eight.left = &three;
    eight.right = &ten;
    three.left = &one;
    three.right = &six;
    six.left = &four;
    six.right = &seven;
    ten.right = &fourteen;
    fourteen.left = &thirteen;
    
    levelTraversal(&eight);
    
    return 0;
}



