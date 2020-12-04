/*
DSA Foundations - Binary Tree                                                    Date: 01-Dec-2020

1. You are given a partially written BinaryTree class.
2. You are required to complete the body of printSingleChildNodes function. The function is expected to print in separate lines, all such nodes which are only child of their parent. Use preorder for traversal.
3. Input and Output is managed for you.
*/


public static void printSingleChildNodes(Node node, Node parent){
    // base case
    if(node == null)
        return;
        
    // preorder expectation
    if(parent != null && parent.left == node && parent.right == null) 
        System.out.println(node.data);
    else if(parent != null && parent.right == node && parent.left == null) 
        System.out.println(node.data);
        
    //faith - calling
    printSingleChildNodes(node.left, node);
    printSingleChildNodes(node.right, node);
  }