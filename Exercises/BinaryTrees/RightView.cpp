/* returns the elements on the right side of the convex hull of the tree
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void rightView(TreeNode* root){
    // use a queue to manage nodes. the trick is to push
    // an entire level of nodes onto the queue after each for
    // loop, but the first element will be the rightmost
    queue<TreeNode*> q;
    q.emplace(root);
    
    while (!q.empty){
        int size = q.size();
        // iterate over the size of the queue, and put the
        // right then the left node into the queue
        for (int i = 0; i < size; i++){
            TreeNode* top = q.remove();
            if (i==0){
                cout << top->value << endl;
            }
            q.emplace(top->right);
            q.emplace(top->left);
        }
    }
    
    return;
}

