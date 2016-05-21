/* determines if a binary tree is a valid binary search tree
 * 
 * tools used: recursion
 */

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value): value(value), left(nullptr), right(nullptr){};
};

bool validateBST(TreeNode* head, int beg, int end){
    if (!head) return true;
    else if (head->value<beg || head->value>end) return false;
    else return validateBST(head->left, beg, head->value) \
        && validateBST(head->right, head->value, end);
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
    fourteen.right = &thirteen;
    
    cout << validateBST(&eight, INT_MIN, INT_MAX);
    
    return 0;
}
