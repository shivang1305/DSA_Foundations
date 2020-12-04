/*
DSA Foundations - Binary Tree                                                    Date: 30-Nov-2020

1. You are given a partially written BinaryTree class.
2. You are given a value lo and a value hi
3. You are required to complete the body of pathToLeafFromRoot function. The function is expected to print all paths from root to leaves which have sum of nodes in range from lo to hi (both inclusive). The elements in path should be separated by spaces. Each path should be in a separate line.
4. Input is managed for you.
*/


public static void pathToLeafFromRoot(Node node, String path, int sum, int lo, int hi){
    if(node == null) //base case
        return;
        
    //we have to decide to print only when we reach leaf node
    if(node.left == null && node.right == null) {
        sum += node.data; //to add the value of current node also
        if(sum >= lo && sum <= hi)
            System.out.println(path + node.data); //adding cuurent node to the path before printing it
        return;
    }
        
    pathToLeafFromRoot(node.left, path + node.data + " ", sum + node.data, lo, hi);
    pathToLeafFromRoot(node.right, path + node.data + " ", sum + node.data, lo, hi);
  }