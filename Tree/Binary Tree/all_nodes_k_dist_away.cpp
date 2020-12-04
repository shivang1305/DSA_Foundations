/*
DSA Foundations - Binary Tree                                                    Date: 29-Nov-2020

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.


Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
*/

vector<TreeNode*> path;
bool find(TreeNode* root, TreeNode* target) {
    //base case of recursive call
    if(root == NULL)
        return false;

    //self checking
    if(root == target) {
        path.push_back(root);
        return true;
    }

    //checking in the left subtree
    bool lft = find(root->left, target);
    if(lft) {
        path.push_back(root);
        return true;
    }

    //checking in the right subtree
    bool rght = find(root->right, target);
    if(rght) {
        path.push_back(root);
        return true;
    }

    return false; //if the node does not matches in the left and right subtree then only compiler will reach at this statement
}
    
vector<int> temp;
void KLevelsDown(TreeNode* root, int k, TreeNode* blocker) {
    //base case
    if(root == NULL || k<0 || root == blocker)
        return;
        
    if(k == 0) 
        temp.push_back(root->val);
    
    //blocker is used to block the path in which the target node is there.
    KLevelsDown(root->left, k-1, blocker);
    KLevelsDown(root->right, k-1, blocker);
}
    
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    find(root, target);
        
    for(int i=0; i<path.size(); i++) 
        KLevelsDown(path[i], K-i, i==0 ? NULL : path[i-1]); //giving the blocker to block the certain paths
        
    vector<int> ans;
    ans.insert(ans.end(), temp.begin(), temp.end()); //concatenating with ans 
        
    return ans;
}