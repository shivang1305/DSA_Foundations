/*                                                                               Date: 01-Nov-2020
Find the inorder successor and predecessor of the given node in the generic tree.
1. You are given a partially written GenericTree class.
2. You are required to find the preorder predecessor and successor of a given element. Use the "travel and change" strategy explained in the earlier video. The static properties have been declared for you. You can declare more if you want.
3. Input and Output is managed for you.
*/

  //these variables get allocated inside the heap memory
  static Node predecessor;
  static Node successor;
  static int state; //before the target element set state to 0 , at the target element set the state to 1, and after that set state to 2
  //last element while state is 0 is our predecessor and the last element having state 1 is our successor

  public static void predecessorAndSuccessor(Node node, int data) { //data gets allocated in the stack memory which changes with state of the recursion
    //Preorder area
    if(state == 0) {
        if(node.data == data)
            state = 1; //change the state
        else
            predecessor = node; //change the predecessor
    }
    else if(state == 1) {
        successor = node;
        state = 2;
    }

    for(Node child : node.children)
        predecessorAndSuccessor(child, data); //recursive calling for traversal inside the tree
  }
