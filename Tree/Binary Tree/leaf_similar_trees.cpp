/*
Leetcode - Binary Tree                                                      Date: 01-Dec-2020

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    vector<int> returnLeaves(TreeNode* root) {
        // base case
        if(root == NULL)
            return vector<int>();
        
        vector<int> l = returnLeaves(root->left);
        vector<int> r = returnLeaves(root->right);
        
        //when the euler reaches to the leaf node
        if(root->left == NULL && root->right == NULL)
            l.push_back(root->val); // pushing only the leaf nodes to the list
        
        //concatenate all the vectors 
        l.insert(l.end(), r.begin(), r.end());
        
        return l;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return returnLeaves(root1) == returnLeaves(root2);
    }
};