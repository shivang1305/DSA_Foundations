/*
DSA Foundations - Binary Tree                                                    Date: 01-Dec-2020

1. You are given a partially written BinaryTree class.
2. You are required to complete the body of removeLeaves function. The function is expected to remove all leaf nodes from the tree.
3. Input and Output is managed for you. 
*/


public static Node removeLeaves(Node node){
    // base case
    if(node == null)
        return null;
    
    //when the approached node is leaf node    
    if(node.left == null && node.right == null)
        return null;
    
    node.left = removeLeaves(node.left);
    node.right = removeLeaves(node.right); 
    
    return node;
  }
