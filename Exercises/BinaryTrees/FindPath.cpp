/* finds the paths for which the sum is equal to some target
 * 
 * tools: depth first search
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

void findPath(TreeNode* head, int target, vector<int>& myVec){
    // if we have reached the end of a node
    if (!head){
        return;
    }
    else if (!(head->left) && !(head->right)){
        myVec.push_back(head->value);
        if (accumulate(myVec.begin(), myVec.end(),0) == target){
            copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
        return;
    }
    // otherwise, recurse down
    else{
        vector<int> newVec;
        copy(myVec.begin(), myVec.end(), back_inserter(newVec));
        myVec.push_back(head->value);
        newVec.push_back(head->value);
        findPath(head->left, target, myVec);
        findPath(head->right, target, newVec);
        return;
    }
}

int main(){
    TreeNode five(5);
    TreeNode eight(8);
    TreeNode four(4);
    TreeNode eleven(11);
    TreeNode thirteen(13);
    TreeNode fourAgain(4);
    TreeNode seven(7);
    TreeNode two(2);
    TreeNode fiveAgain(5);
    TreeNode one(1);
    
    five.left = &four;
    five.right = &eight;
    four.left = &eleven;
    eleven.left = &seven;
    eleven.right = &two;
    eight.left = &thirteen;
    eight.right = &fourAgain;
    fourAgain.left = &fiveAgain;
    fourAgain.right = &one;
    
    vector<int> myVec;
        
    findPath(&five, 22, myVec);
    
    
    return 0;
}
