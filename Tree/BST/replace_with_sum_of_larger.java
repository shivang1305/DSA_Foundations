/*
    DSA Foundations - Binary Search Tree                                           Date: 09-Dec-2020

1. You are given a partially written BST class.
2. You are required to complete the body of rwsol function. "rwsol" function is expected to replace a node's value with sum of all nodes greater than it.
3. Input and Output is managed for you. 
*/  
  
  static int sum = 0;
  public static void rwsol(Node node){
    // base case
    if(node == null)
        return;
    
    // reverse inorder traversal (Right Root Left)
    
    rwsol(node.right); 
    
    int orignalData = node.data;
    node.data = sum;
    sum += orignalData;
    
    rwsol(node.left);
  }