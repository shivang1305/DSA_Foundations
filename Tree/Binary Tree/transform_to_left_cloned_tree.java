/*
DSA Foundations - Binary Tree                                                    Date: 01-Dec-2020

1. You are given a partially written BinaryTree class.
2. You are required to complete the body of createLeftCloneTree function. The function is expected to create a new node for every node equal in value to it and inserted between itself and it's left child. Check question video for clarity.
3. Input and Output is managed for you.
*/


public static Node createLeftCloneTree(Node node) {
    //base case
    if(node == null)
        return null;
        
    //faith
    Node leftClone = createLeftCloneTree(node.left);
    Node rightClone = createLeftCloneTree(node.right);
    
    //expectations
    Node newNode = new Node(node.data, leftClone, null);
    node.left = newNode;
    node.right = rightClone;
    
    return node;
}
