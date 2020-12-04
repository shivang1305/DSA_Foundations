/*
DSA Foundations - Binary Tree                                                    Date: 20-Nov-2020

Iterative approach for Preorder, Inorder and Postorder traversal of binary tree.
*/

public static void iterativePrePostInTraversal(Node node) {
    //Using stack and state approach to manually do recursion 
    Stack<Pair> st = new Stack<>();
    Pair rootPair = new Pair(node, 1);

    st.push(rootPair);

    String pre = "", in = "", post = "";

    while(st.size() > 0) {
        Pair top = st.peek();

        if(top.state == 1) { //preorder, state++, left
            pre += top.node.data + " ";
            top.state++;

            if(top.node.left != null) {
                Pair leftPair = new Pair(top.node.left, 1);
                st.push(leftPair);
            }
        }
        else if(top.state == 2) { //inorder, state++, right
            in += top.node.data + " ";
            top.state++;

            if(top.node.right != null) {
                Pair rightPair = new Pair(top.node.right, 1);
                st.push(rightPair);
            }
        }
        else if(top.state == 3) { //postorder, pop
            post += top.node.data + " ";
            st.pop();
        }
    }

    System.out.println(pre);
    System.out.println(in);
    System.out.println(post);
  }
