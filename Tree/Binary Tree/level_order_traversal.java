/*
DSA Foundations - Binary Tree                                                    Date: 20-Nov-2020

Perform the Level Order Traversal of binary tree.
*/

public static void levelOrder(Node node) {
    Queue<Node> que = new ArrayDeque<>();
    que.add(node); //adding root node to the queue

    while(que.size() > 0) {
        int currSize = que.size(); //obtaining the current size of the queue for each level
        for(int i=1; i<=currSize; i++) { //making for loop run for the number of times the size at current level
            node = que.remove();
            System.out.print(node.data + " ");

            if(node.left != null)
                que.add(node.left);

            if(node.right != null)
                que.add(node.right);
        }

        System.out.println();
    }
  }
