/**
 * 226. Invert Binary Tree
Easy

Invert a binary tree.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.3 MB, less than 10.96% of C++ online submissions for Invert Binary Tree.
Next challenges: 
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == NULL){
            return NULL;
        }
        
        // Invert recursively invert left and right hand side
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        
        // Swap left and right
        root->left = right;
        root->right = left;

        return root;    
    }
};