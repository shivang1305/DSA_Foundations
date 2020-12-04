/*
DSA Foundations - Binary Tree                                                    Date: 04-Dec-2020

1. You are given a partially written BinaryTree class.
2. You are required to find the root of largest sub-tree which is a BST. Also, find the number of nodes in that sub-tree.
3. Input is managed for you. 
*/

// BST Class
public static class BSTPair {
    boolean isBST;
    int max;
    int min;
    Node root; // largest BST root 
    int size; // largest BST size 
    // this root and size may or may not be of the curr node, it is possible that curr node is representing its subtree's root and size if that curr node is not BST
}

public static BSTPair isBst(Node node) {
    // base case
    if(node == null) {
        BSTPair p = new BSTPair();
        p.isBST = true;
        p.min = Integer.MAX_VALUE;
        p.max = Integer.MIN_VALUE;
        p.root = null;
        p.size = 0;
        return p;
    }
    
    // faith
    BSTPair lp = isBst(node.left);
    BSTPair rp = isBst(node.right);
    
    // expectation
    BSTPair mp = new BSTPair();
    // current node as a tree will be BST only if its left and right subtree is a BST and its value is greater than all nodes value of left subtree and less than all nodes value of its right subtree 
    mp.isBST = lp.isBST && rp.isBST && node.data >= lp.max && node.data <= rp.min;
    mp.min = Math.min(node.data, Math.min(lp.min, rp.min));
    mp.max = Math.max(node.data, Math.max(lp.max, rp.max));
    
    if(mp.isBST) {
        mp.root = node; // largest BST root is the current node itself if it is BST
        mp.size = lp.size + rp.size + 1; // size is also added accordingly
    }
    // if curr node is not satisfying BST conditions then we check for left and right nodes size, here it might be possible that lp or rp might not be BST but in that case they are storing largest BST subtree in their root and size.
    else if(lp.size > rp.size) {  
        mp.root = lp.root;
        mp.size = lp.size;
    }
    else {
        mp.root = rp.root;
        mp.size = rp.size;
    }
    
    return mp;
}