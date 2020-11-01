/*                                                                               Date: 19-Oct-2020
1. You are given a partially written GenericTree class.
2. You are required to complete the body of size function. The function is expected to count the number of nodes in the tree and return it.
3. Input and Output is managed for you.
*/

/* Recursive approach - High level thinking */
public static int size(Node node){
    int size = 0;
    for(Node child: node.children) {
        int childSize = size(child); //recursive calling for all the children of current node
        size += childSize; //adding child size to the parent node
    }

    size += 1; //for the node itself

    return size;
  }
