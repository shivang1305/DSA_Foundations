/*
    DSA Foundations - Binary Search Tree                                           Date: 09-Dec-2020

1. You are given a partially written BST class.
2. You are required to complete the body of pir function. "pir" function is expected to print all nodes between d1 and d2 (inclusive and in increasing order).
3. Input and Output is managed for you. 
*/ 


public static void pir(Node node, int d1, int d2) {
    // base case
    if(node == null)
        return;
        
    // faith (left)
    pir(node.left, d1, d2);
    
    // expectation (inorder)
    if(node.data >= d1 && node.data <= d2)
        System.out.println(node.data);
    
    // faith (right)
    pir(node.right, d1, d2);
}