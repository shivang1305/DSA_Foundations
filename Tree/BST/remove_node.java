/*
    DSA Foundations - Binary Search Tree                                           Date: 09-Dec-2020

1. You are given a partially written BST class.
2. You are required to complete the body of remove function. "remove" function is expected to remove a new node with given data to the tree and return the new root.
3. Input and Output is managed for you. 
*/

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

public static Node remove(Node node, int data) {
    // base case
    if(node == null)
        return null;
    
    // finding the node
    if(node.data < data)
        node.right = remove(node.right, data);
    
    else if(node.data > data)
        node.left = remove(node.left, data);
    
    // node is found
    else { // when the data is equal to node.data i.e when we have found the node to be deleted
        if(node.left != null && node.right != null) {
            int lmax = max(node.left);
            node.data = lmax;
            node.left = remove(node.left, lmax);
            return node;
        }
        
        else if(node.left != null) 
            return node.left;
        
        else if(node.right != null) 
            return node.right;
        
        else  // when both the children are null i.e in case of leaf node
            return null;
    }
    
    return node;
}
