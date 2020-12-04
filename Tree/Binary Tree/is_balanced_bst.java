/*
DSA Foundations - Binary Tree                                                    Date: 03-Dec-2020

1. You are given a partially written BinaryTree class.
2. You are required to check if the tree is balanced. A binary tree is balanced if for every node the gap between height's of it's left and right subtree is not more than 1.
*/

// Travel and Change Strategy
static boolean balanced = true;
public static int isBalanced(Node node) {
    if(node == null) // base case
      return 0;
      
    // faith
    int leftHt = isBalanced(node.left);
    int rightHt = isBalanced(node.right);
    
    // expectation
    if(Math.abs(leftHt - rightHt) > 1)
      balanced = false;
    
    return Math.max(leftHt, rightHt) + 1;
}