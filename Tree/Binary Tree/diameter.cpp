/*
Leetcode - Binary Tree                                                      Date: 02-Dec-2020

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    /** Approach 1 - Brute force recursion **/

    int height(TreeNode* root) {
        // base case
        if (root == NULL) 
            return -1;
    
        // faith
        int lh = height(root->left);
        int rh = height(root->right);

        // expectation
        int th = max(lh, rh) + 1;
        
        return th;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(root == NULL)
            return 0;
        
        //expectation
        int dia = height(root->left) + height(root->right) + 2; //in the postorder of a recursive function call to another recursive function makes the time complexity of our code as O(N^2)
        
        //faith
        return max(dia, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
     /** Approach 2 -  Returning diameter and height together from the same function**/

    pair<int, int> diaTree(TreeNode* root) {
        // base case
        if(root == NULL) {
            pair<int, int> temp;
            temp.first = -1; //first = height
            temp.second = 0; //second = diameter
            return temp;
        }
        
        //faith
        pair<int, int> lft = diaTree(root->left);
        pair<int, int> rght = diaTree(root->right);
        
        //expectation
        pair<int, int> ans;
        ans.first = max(lft.first, rght.first) + 1;
        ans.second = max(lft.first + rght.first + 2, max(lft.second, rght.second));
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> daimeter = diaTree(root);
        
        return daimeter.second;
    }

    /** Approach 3 - Travel and Change strategy **/
    
    int dia;
    //this function returns height but also changes the dia accordingly in each call
    int diaTree(TreeNode* root) {
        // base case
        if(root == NULL) 
            return -1;
        
        
        //faith
        int lft = diaTree(root->left);
        int rght = diaTree(root->right);
        
        //expectation
        dia = max(lft + rght + 2, dia);
        
        return max(lft, rght) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diaTree(root);
        
        return dia;
    }
};