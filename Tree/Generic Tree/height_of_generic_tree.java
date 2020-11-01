/*                                                                               Date: 19-Oct-2020
1. You are given a partially written GenericTree class.
2. You are required to complete the body of height function. The function is expected to find the height of tree. Depth of a node is defined as the number of edges it is away from the root (depth of root is 0). Height of a tree is defined as depth of deepest node.
3. Input and Output is managed for you.
*/

public static int height(Node node) {
    int h = -1; //to handle the base case as in case of one single node this function should and will return 0 but if we take h=0 then it would be returing 1 which is wrong ans when we calc the height of tree in terms of the edges

    for(Node child : node.children) {
       int childHeight = height(child); //height of child subtrees
       h = Math.max(h, childHeight); //comparing and obtaining the max height
    }

    h += 1; //to get height from function calling node
    return h;

  }
