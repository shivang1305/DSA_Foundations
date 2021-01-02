/*
    DSA Foundations - Binary Search Tree                                           Date: 08-Dec-2020

1. You are given a partially written BST class.
2. You are required to complete the body of add function. "add" function is expected to add a new node with given data to the tree and return the new root.
3. Input and Output is managed for you.
*/

public static Node add(Node node, int data) {
    // base case
    if(node == null)
        return new Node(data, null, null); // returning the new node
        
    // faith & expectations
    if(node.data > data)
        node.left = add(node.left, data);
        
    else if(node.data < data)
        node.right = add(node.right, data);
        
    return node; // returning the root node
  }