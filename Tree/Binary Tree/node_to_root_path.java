/*
DSA Foundations - Binary Tree                                                    Date: 29-Nov-2020

Node to root path for a given node in a binary tree.

1. You are given a partially written BinaryTree class.
2. You are given an element.
3. You are required to complete the body of find and nodeToRoot function. The functions are expected to 
    3.1. find -> return true or false depending on if the data is found in binary tree.
    3.2. nodeToRoot -> returns the path from node (correspoding to data) to root in 
    form of an arraylist (root being the last element)
4. Input iand Output is managed for you.
*/

static ArrayList<Integer> path;
  public static boolean find(Node node, int data){
    //base case of recursive call
    if(node == null)
        return false;
    
    //self checking
    if(node.data == data) {
        path.add(node.data);
        return true;
    }
    
    //checking in the left subtree
    boolean lft = find(node.left, data);
    if(lft) {
        path.add(node.data);
        return true;
    }
    
    //checking in the right subtree
    boolean rght = find(node.right, data);
    if(rght) {
        path.add(node.data);
        return true;
    }
    
    return false; //if the node does not matches in the left and right subtree then only compiler will reach at this statement
  }
