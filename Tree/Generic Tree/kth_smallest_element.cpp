/*    Leetcode - Kth smallest element in BST (medium)                             Date: 05-Nov-2020
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
*/

class Solution {
public:
    int getCeil(TreeNode* root, int data) {
        if(root == NULL)
            return INT_MAX;
        int ceil = INT_MAX;
        if(root->val > data && root->val < ceil)
            ceil = root->val;

        return min(ceil, min(getCeil(root->left, data), getCeil(root->right, data)));
    }
    int kthSmallest(TreeNode* root, int k) {
        int ceil = INT_MAX;
        int kMin = INT_MIN;

        //this loop will obtain the values of tree in ascending order k times
        for(int i=1; i<=k ; i++) {
            ceil = getCeil(root, kMin);
            kMin = ceil;
            ceil = INT_MAX; //setting ceil to its orignal value
        }
        return kMin;
    }
};
