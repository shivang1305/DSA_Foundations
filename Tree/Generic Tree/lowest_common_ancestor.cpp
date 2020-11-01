/* Leetcode - Lowest Common Ancestor (medium)                                    Date: 01-Nov-2020
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //edge case
        if(root == NULL)
            return NULL;

        if(root->val == p->val || root->val == q->val)
            return root;

        //recursive calls towards left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //left call
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //right call

        return (left != NULL && right != NULL) ? root : (left != NULL) ? left : right;
    }
};
