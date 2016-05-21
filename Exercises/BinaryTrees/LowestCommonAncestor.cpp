/* finds the lowest common ancestor of two nodes in a binary tree
 *
 */

#include <iostream>

using namespace std;

// treenode plus an int representing a count, which will be set to 0 if neither
// p nor q are in its subtree, 1 if p or q are in the subtree, and 2 if both
struct TreeCountNode{
    TreeNode* node;
    int count;
    TreeCountNode(int count, TreeNode* node): node(node), count(count){};
};

// returns a TreeCountNode containing argument node  plus a count;
// it achieves this via recursion
TreeCountNode* lcaHelper(TreeNode* node, TreeNode* p, TreeNode* q){
    // recurse to the left
    TreeCountNode* left = lcaHelper(node->left, p, q);
    // check if count is 2; if it is 2, return the node
    // this works because the recursion happens before the check, so it starts 
	// from the bottom of the tree and works up
    if (left.count == 2) return left;
    
    // mirror for right
    TreeCountNode* right = lcaHelper(node->right, p, q);
    if (right.count==2) return right;
    
    // add the two counts into a total
    int total = left.count + right.count;
    // if either of them match the nodes add 1 to the total
    if (node==p || node==q) total++;
    
    // return pointer to TreeCountNode
    return new TreeCountNode(total, node);
    
}
