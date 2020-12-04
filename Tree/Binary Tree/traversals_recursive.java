/*
DSA Foundations - Binary Tree                                                    Date: 20-Nov-2020

Recursive approach for Preorder, Inorder and Postorder traversal of binary tree.
*/


    public static void preOrder(Node node) {
        if(node == null)
            return;

        System.out.print(node.data + " ");

        preOrder(node.left);
        preOrder(node.right);
    }

    public static void inOrder(Node node) {
        if(node == null)
            return;

        inOrder(node.left);

        System.out.print(node.data + " ");

        inOrder(node.right);
    }

    public static void postOrder(Node node) {
        if(node == null)
            return;

        postOrder(node.left);
        postOrder(node.right);

        System.out.print(node.data + " ");
    }
