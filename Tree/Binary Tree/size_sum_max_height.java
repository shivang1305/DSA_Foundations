/*
DSA Foundations - Binary Tree                                                    Date: 17-Nov-2020

Given a binary tree print the sum, height, size & max node in the tree.
*/

//recursive approach for all functions

public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = "";
    str += node.left == null ? "." : node.left.data + "";
    str += " <- " + node.data + " -> ";
    str += node.right == null ? "." : node.right.data + "";
    System.out.println(str);

    display(node.left);
    display(node.right);
  }

  public static int size(Node node) {
    if(node == null)
        return 0;

    int leftSize = size(node.left);
    int rightSize = size(node.right);

    int totalSize = leftSize + rightSize + 1;

    return totalSize;
  }

  public static int sum(Node node) {
    if(node == null)
        return 0;

    int leftSum = sum(node.left);
    int rightSum = sum(node.right);

    int totalSum = leftSum + rightSum + node.data;

    return totalSum;
  }

  public static int max(Node node) {
    if(node == null)
        return Integer.MIN_VALUE;

    int leftMax = max(node.left);
    int rightMax = max(node.right);

    int overallMax = Math.max(node.data, Math.max(leftMax, rightMax));

    return overallMax;
  }

  public static int height(Node node) {
    if(node == null)
        return -1; //return -1 when you measure height in edges & return 0 if you are measuring height in terms of nodes.

    int leftHeight = height(node.left);
    int rightHeight = height(node.right);

    int overallHeight = Math.max(leftHeight, rightHeight) + 1;

    return overallHeight;
  }
