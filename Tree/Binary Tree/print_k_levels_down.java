/*
DSA Foundations - Binary Tree                                                    Date: 29-Nov-2020

Node to root path for a given node in a binary tree.

1. You are given a partially written BinaryTree class.
2. You are given a value k.
3. You are required to complete the body of printKLevelsDown function. The function is expected to print in different lines all nodes which are k level deep. Use preorder for printing.
4. Input is managed for you.
*/

public static void printKLevelsDown(Node node, int k){
    //base case
    if(node == null || k < 0)
        return;
    
    if(k == 0)
        System.out.println(node.data);
        
    //level will be decremented at each recursive call
    printKLevelsDown(node.left, k-1); 
    printKLevelsDown(node.right, k-1);
  }