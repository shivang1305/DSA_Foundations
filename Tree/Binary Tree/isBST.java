/*
DSA Foundations - Binary Tree                                                    Date: 03-Dec-2020

1. You are given a partially written BinaryTree class.
2. You are required to check if the tree is a Binary Search Tree (BST) as well. In a BST every node has a value greater than all nodes on it's left side and smaller value than all node on it's right side.
*/

// BST Class
  public static class BSTPair {
      boolean isBST;
      int max;
      int min;
  }
  
  public static BSTPair isBst(Node node) {
      // base case
      if(node == null) {
          BSTPair p = new BSTPair();
          p.isBST = true;
          p.min = Integer.MAX_VALUE;
          p.max = Integer.MIN_VALUE;
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
      
      return mp;
  }