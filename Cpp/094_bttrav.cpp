#include <iostream>
#include <vector>
#include <stack>
#include "Ref/seb_util.c"

using namespace std;

// BT node
struct TreeNode{
    int val; // value @ node
    TreeNode *left; // pointer to left node
    TreeNode *right; // pointer to right node

    // Init
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    // https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31232/Three-Methods-to-Solve-(C++)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){return ans;}
        //  create a stack of tree node pointers
        stack<TreeNode *> temp;
        // push root on stack
        temp.push(root);

        while(!temp.empty()){

            // set current node to top of stack
            TreeNode *current = temp.top();

            // go to left
            if(current->left){
                // push left node to stack
                temp.push(current->left);
                current->left = NULL;
            }
            else{
                // otherwise add to end of stack
                ans.push_back(current->val);
                // get next node in stack
                temp.pop();
                // traverse to the right
                if(current->right){
                    temp.push(current->right);
                }
            }
        }
        return ans;
    }
};


int main(){

    TreeNode root(1);
    TreeNode nodea(2);
    TreeNode nodeb(3);

    Solution soln;
    vector<int> ans;
    ans = soln.inorderTraversal(&root);
    cout << ans[0];
    // cout << printvect1d<int>(ans) << endl;

    return 0;
}
