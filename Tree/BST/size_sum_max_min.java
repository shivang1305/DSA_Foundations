/*
    DSA Foundations - Binary Search Tree                                           Date: 08-Dec-2020

1. You are given a partially written BST class.
2. You are required to complete the body of size, sum, max, min and find function. The functions are expected to:
    2.1. size - return the number of nodes in BST
    2.2. sum - return the sum of nodes in BST
    2.3. max - return the value of node with greatest value in BST
    2.4. min - return the value of node with smallest value in BST
    2.5. find - return true if there is node in the tree equal to "data"
3. Input and Output is managed for you.
*/

public static int size(Node node) {
    // base case
    if(node == null) 
        return 0;
    
    // faith
    int leftSize = size(node.left);
    int rightSize = size(node.right);
    
    // expectation
    int totalSize = leftSize + rightSize + 1;
    
    return totalSize;
  }

  public static int sum(Node node) {
    // base case
    if(node == null)
        return 0;
        
    // faith
    int leftSum = sum(node.left);
    int rightSum = sum(node.right);
    
    int totalSum = leftSum + rightSum + node.data;
    
    return totalSum;
  }
    
  // max node in BST will be the right most node
  public static int max(Node node) {
    // base cases 
    if(node == null)
        return 0;
    if(node.right == null)
        return node.data;
    
    // faith and expectation
    return max(node.right);
  }

  // min node in BST will be the left most node
  public static int min(Node node) {
    // base cases 
    if(node == null)
        return 0;
    if(node.left == null)
        return node.data;
    
    // faith and expectation
    return min(node.left);
  }

  public static boolean find(Node node, int data){
    // base case
    if(node == null)
        return false;
    
    // expectation
    if(node.data == data) 
        return true;
    
    // faith
    if(node.data < data) // will go to right in that case
        return find(node.right, data);
    
    return find(node.left, data); // will go in left direction in that case
  }