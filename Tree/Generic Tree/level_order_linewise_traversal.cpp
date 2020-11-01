/*                                                                               Date: 21-Oct-2020
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(!root) //edge case
            return ans;

        /*
           APPROACH 1 - Two queues

        queue<TreeNode*> mainQ; //for storing the currrent node
        queue<TreeNode*> childQ; //for storing all the children of current node

        vector<int> temp;

        mainQ.push(root); //adding root element to the queue

        while(mainQ.size() > 0) { //time complexity = O(N)

            root = mainQ.front();
            temp.push_back(root->val);

            if(root != NULL) {
                if(root->left)
                    childQ.push(root->left);
                if(root->right)
                    childQ.push(root->right);
            }

            mainQ.pop();

            if(mainQ.size() == 0) { //when main queue is empty then swap mainQ and childQ
                swap(mainQ, childQ);
                ans.push_back(temp); //push the array into the final ans
                temp.clear();
            }
        }

        */


        /* APPROACH 2 - One queue and one markel which marks and checks for null

        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL); //adding null for checking that the current level is completed

        vector<int> temp;

        while(!que.empty()) {
            root = que.front();

            if(root != NULL) {
                temp.push_back(root->val);

                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->right);

                que.pop();
            }

            else {
                ans.push_back(temp);
                temp.clear();

                que.pop();
                if(que.size() > 0)
                    que.push(NULL); //pushing null element to the end of the queue only if size of queue > 0
            }

        }

        */

        /* APPROACH 3 - Calculating the size of queue at each level and running a loop till the size  */

        queue<TreeNode*> que;
        que.push(root);

        vector<int> temp;


        while(!que.empty()) {
            int currSize = que.size();

            for(int i=0; i<currSize; i++) {
                root = que.front();
                temp.push_back(root->val);

                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->right);

                que.pop();
            }

            ans.push_back(temp);
            temp.clear();

        }


        return ans;

    }
};
