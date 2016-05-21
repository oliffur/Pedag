/* populates each TreeNode with a pointer to the node to its right
 *
 */


#include <iostream>

using namespace std;

void connect(TreeNode* root){
    // 2 pointers for the previous level; one pointing to the beginning node of 
	// the previous level, and another pointing to the a node of the previous 
	// level of which the current node is a child
    TreeNode* prevBeg = root;
    TreeNode* prevNod = nullptr;
    
    // 2 pointers for the current level; one pointing to the node that we are 
	// looking at (a child of prevNod), and another pointing to the right 
	// pointer of that node;
    TreeNode* currBeg = nullptr;
    TreeNode* currNod = nullptr;
    
    // each while loop goes through one level
    while (prevBeg){
        // set the prevNod level to the beginning
        prevNod = prevBeg;
        
        // each while loop here goes through one row
        while (prevNod){
            // if this is the first node in the row
            if (!currNod){
                // current node and its right set to the left of the parent
                currBeg = prevNod->left;
                currNod = prevNod->left;
            }
            // if it is not the first node, then bridge the gap
            else{
                // bridge gap, then move current pointer to the right
                currNod->next = prevNod->left;
                currNod = currNod->next;
            }
            
            // bridge gap again, but now between left and right nodes of
            // the same parent, the node pointed to by prevNod
            if (currNod){
                currNod->next = prevNod->right;
                currNod = currNod->next;
            }
            
            // move the prevNod pointer to the right
            prevNod = prevNod->next;
        }
        // change levels
        prevBeg = currBeg;
        currBeg = nullptr;
    }
    
}
