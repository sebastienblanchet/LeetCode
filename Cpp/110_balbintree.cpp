#include <cmath>
#include "helpBinTree.h"

/*
TreeNode *        = 
110. Balanced Binary Tree
Easy

Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:

A binary tree in which the depth of the two subtrees of every 
node never differ by more than 1.

    3
   / \
  9  20
    /  \
   15   7
TRUE

Definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/



class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if (root == NULL){
            return true;
        }

        return helper(root) != -1;

    }
private:
    int helper(TreeNode* root){

        if (root == NULL){
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1){
            return -1;
        }

        return fmax(left, right) + 1;
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *h   = new TreeNode(3); 
    TreeNode *l   = new TreeNode(9); 
    TreeNode *r   = new TreeNode(20); 
    TreeNode *rl  = new TreeNode(7); 
    TreeNode *rr  = new TreeNode(15); 
    h->left = l;
    h->right = r;
    r->left = rl;
    r->right = rr;
    std::cout<< Solution().isBalanced(h) << std::endl;
    
    return 0;
}