/*
    DSA Foundations - Binary Search Tree                                           Date: 09-Dec-2020

1. You are given a partially written BST class.
2. You are required to complete the body of lca function. "lca" function is expected to find the lowest commong ancestor of d1 and d2.
3. Input and Output is managed for you. 
*/ 

public static int lca(Node node, int d1, int d2) {
    if(node.data > d1 && node.data > d2)
        return lca(node.left, d1, d2);
    
    else if(node.data < d1 && node.data < d2)
        return lca(node.right, d1, d2);
    
    else // in between d1 & d2 i.e the last common element in node to root path which will be the lowest common ancestor.
        return node.data;
}