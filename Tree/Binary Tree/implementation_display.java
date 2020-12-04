/*
DSA Foundations - Binary Tree                                                    Date: 17-Nov-2020

Give the basic implementation of binary tree, write its display function and the constructor also in the binary tree class.
*/

import java.util.*;

public class Main{

    public static class Node {
        int data;
        Node left;
        Node right;

        //parameterized constructor for tree
        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public static class Pair {
        Node node;
        int state;

        Pair(Node node, int state) {
            this.node = node;
            this.state = state;
        }
    }

    public static void display(Node node) {
        if(node == null) //base case of recursion
            return;

        String str = "";

        //using ternary operators to check for null node and add . in case of null node and value in case of non-null node
        str += node.left == null ? "." : node.left.data + "";
        str += " <- " + node.data + " -> ";
        str += node.right == null ? "." : node.right.data + "";

        System.out.println(str);

        //recursive calling to the left and right child of current  node
        display(node.left);
        display(node.right);

    }

    public static void main(String[] args) {
        Integer[] arr = {50, 25, 12, null, null, 37, 30, null, null, null, 75, 62, null, 70, null, null, 87, null, null};

        Stack<Pair> st = new Stack<>();

        Node root = new Node(arr[0], null, null);

        /*
            state 1 - incoming node will be attached to the left of node
            state 2 - incoming node will be attached to the right of node
            state 3 - left and right child of current node are filled so it will be popped from the stack
        */
        Pair rootNode = new Pair(root, 1);
        st.push(rootNode);

        int idx = 0;

        while(st.size() > 0) {
            Pair top = st.peek();

            if(top.state == 1) { //LEFT CHILD
                idx++;

                if(arr[idx] != null) { //only for non null values of arr
                    Node leftNode = new Node(arr[idx], null, null); //creating the new node for left child
                    top.node.left = leftNode; //attaching the node to the left of current node

                    Pair leftPair = new Pair(leftNode, 1); //creating a pair for left node & assigning the state as 1
                    st.push(leftPair); //pushing the left pair into the stack with state 1
                }

                top.state++; //increasing the state of current node as it has its left child attached
            }
            else if(top.state == 2) { //RIGHT CHILD
                idx++;

                if(arr[idx] != null) { //only for non null values of arr
                    Node rightNode = new Node(arr[idx], null, null); //creating the new node for right child
                    top.node.right = rightNode; //attaching the node to the right of current node

                    Pair rightPair = new Pair(rightNode, 1); //creating a pair for right node & assigning the state as 1
                    st.push(rightPair); //pushing the right pair into the stack with state 1
                }

                top.state++; //increasing the state of current node as it has its right child attached
            }
            else if(top.state == 3)  //NO CHILD
               st.pop();

        }

        display(root);

    }
}
