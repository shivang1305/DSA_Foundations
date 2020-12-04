/*
Leetcode - Binary Tree                                                      Date: 01-Dec-2020

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sumLeft;
    void sumLeftLeaves(TreeNode* root, TreeNode* parent) {
        if(root == NULL) // base case
            return;
        
        // checking for left leaf nodes 
        if(parent != NULL && root->left == NULL && root->right == NULL && parent->left == root)
            sumLeft += root->val;
        
        // recursive calling - faith
        sumLeftLeaves(root->left, root);
        sumLeftLeaves(root->right, root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sumLeftLeaves(root, NULL);
        return sumLeft;
    }
};