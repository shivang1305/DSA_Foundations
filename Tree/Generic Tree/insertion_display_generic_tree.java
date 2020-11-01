/*                                                                               Date: 17-Oct-2020

*/

import java.util.*;

public class Main{

    //node class it defines the structure of the node in a generic tree
    private static class Node {
        int data;
        //this arraylist class is made for generic trees specially because it can have more than one child and arraylist can vary its size
        ArrayList<Node> children = new ArrayList<>();
    }

    //high level recursion to display the tree
    //expectation from root to print itself and its child nodes
    //faith from any node is that it will print itself and its children
    //display(10) -> s(10) + d(20) + d(30) + d(40)
    public static void display(Node node) {
        String str = node.data + " -> ";

        for(Node child : node.children) {
            str += child.data + ", ";
        }

        System.out.println(str);

        for(Node child : node.children) //recursive call for displaying all the child nodes
            display(child);
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

        Node root = null;
        Stack<Node> st = new Stack<>();

        for(int i=0; i<arr.length; i++) {
            if(arr[i] == -1) //right traversal in case of euler path
                st.pop();
            else {
                Node t = new Node(); //make a node
                t.data = arr[i]; //set the data

                if(st.size() > 0)
                    st.peek().children.add(t); //add the incoming node as the child of the top element of the stack
                else
                    root = t; //if the stack is empty then the incoming node must be the root node

                st.push(t);
            }
        }

        display(root);
    }

}
