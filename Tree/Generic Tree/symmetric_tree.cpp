/**                                                                              Date: 27-Oct-2020
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
    bool isMirror(TreeNode* tree1, TreeNode* tree2) {
        if(tree1 == NULL && tree2 == NULL)
            return true;

        if(tree1 == NULL || tree2 == NULL)
            return false;

        if(tree1->val != tree2->val)
            return false;

        return isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);

    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) //edge case
            return true;

        return isMirror(root->left, root->right);
    }
};
