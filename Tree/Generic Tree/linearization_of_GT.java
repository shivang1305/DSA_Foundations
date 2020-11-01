/*                                                                                Date: 28-Oct-2020
1. You are given a partially written GenericTree class.
2. You are required to complete the body of linearize function. The function is expected to create a linear tree i.e. every node will have a single child only. For details check the question video.
3. Input and Output is managed for you.
*/

public static void linearize(Node node){
    for(Node child : node.children)
        linearize(child); //recursive call to go into the depth inside the tree

    while(node.children.size() > 1) {
        Node lastChild = node.children.remove(node.children.size() - 1); //getting the last child of the root element
        Node secondLastChild = node.children.get(node.children.size() - 1); //getting the second last child of root element

        Node tail = getTail(secondLastChild); //getting tail of second last child
        tail.children.add(lastChild); //adding the last child to the tail of second last element so that tree linearizes
    }

  }

  //function to obtain the tail of the given root node of the tree
  public static Node getTail(Node node) {
      while(node.children.size() == 1)
        node = node.children.get(0); //to move to the next level

    return node;
  }
