/*                                                                               Date: 19-Oct-2020
1. You are given a partially written GenericTree class.
2. You are required to complete the body of traversals function. The function is expected to visit every node. While traversing the function must print following content in different situations.
   2.1. When the control reaches the node for the first time -> "Node Pre" node.data.
   2.2. Before the control leaves for a child node from a node -> "Edge Pre"
   node.data--child.data.
   2.3. After the control comes back to a node from a child -> "Edge Post" node.data-
   -child.data.
    2.4. When the control is about to leave node, after the children have been visited
    -> "Node Post" node.data.
3. Input is managed for you.
*/

public static void traversals(Node node) {
    System.out.println("Node Pre " + node.data);

    for(Node child : node.children) {
        System.out.println("Edge Pre " + node.data + "--" + child.data);
        traversals(child); //recursive calling
        System.out.println("Edge Post " + node.data + "--" + child.data);
    }

    System.out.println("Node Post " + node.data);
}
