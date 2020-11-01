/*                                                                               Date: 22-Oct-2020
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) //edge case
            return ans;

        stack<TreeNode*> mainStack;
        mainStack.push(root); //adding root element to the main stack

        stack<TreeNode*> childStack;

        vector<int> temp; //temp vector to hold and store the values of each level
        int level = 0;

        while(!mainStack.empty()) {
            root = mainStack.top();
            temp.push_back(root->val);

            if(root != NULL) {
                if(level % 2 == 0) { //for even levels
                    //insertion of elements from left to right
                   if(root->left)
                       childStack.push(root->left);
                   if(root->right)
                       childStack.push(root->right);
                }
                else{ //for odd levels
                    //insertion of elements is from right to left
                    if(root->right)
                        childStack.push(root->right);
                    if(root->left)
                        childStack.push(root->left);
                }
            }

            mainStack.pop();

            if(mainStack.size() == 0) {
                swap(mainStack, childStack);
                ans.push_back(temp); //pushing one level to final vector
                temp.clear(); //clearing the temp vector so it ready to store the values of a new level
                level++; //increasing the level
            }
        }

        return ans;
    }
};
