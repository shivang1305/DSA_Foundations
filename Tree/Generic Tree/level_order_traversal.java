/*                                                                               Date: 19-Oct-2020
1. You are given a partially written GenericTree class.
2. You are required to complete the body of levelorder function. The function is expected to visit every node in "levelorder fashion". Please check the question video for more details.
3. Input is managed for you.
*/

public static void levelOrder(Node node){
    //Queue based approach
    Queue<Node> q = new ArrayDeque<>();
    q.add(node); //add the first node to the queue

    //iterative approach
    while(q.size() > 0) {
        node = q.remove(); //delete
        System.out.print(node.data + " "); //print

        for(Node child : node.children) //add child
            q.add(child);
    }

    System.out.print(".");
  }
