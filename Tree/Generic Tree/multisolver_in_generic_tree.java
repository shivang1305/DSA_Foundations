/*                                                                                Date: 01-Nov-2020
Creating a single function which dows not return anything yet it solves the many cases for a generic tree such as size, height, max value, min value in a tree.

This function shows a clear difference between heap memory allocation and stack memory allocation.
*/

import java.io.*;
import java.util.*;

public class Main {
  private static class Node {
    int data;
    ArrayList<Node> children = new ArrayList<>();
  }

  public static void display(Node node) {
    String str = node.data + " -> ";
    for (Node child : node.children) {
      str += child.data + ", ";
    }
    str += ".";
    System.out.println(str);

    for (Node child : node.children) {
      display(child);
    }
  }

  public static Node construct(int[] arr) {
    Node root = null;

    Stack<Node> st = new Stack<>();
    for (int i = 0; i < arr.length; i++) {
      if (arr[i] == -1) {
        st.pop();
      } else {
        Node t = new Node();
        t.data = arr[i];

        if (st.size() > 0) {
          st.peek().children.add(t);
        } else {
          root = t;
        }

        st.push(t);
      }
    }

    return root;
  }

  //these variable get memory inside the heap (globally accessible from every function)
  static int size, min, max, height;

  //here depth is a variable that is allocated inside the stack memory which changes with each state of recursion
  public static void multisolver(Node node, int depth) {
      size++;
      min = Math.min(min, node.data);
      max = Math.max(max, node.data);
      height = Math.max(height, depth);
      for(Node child : node.children)
        multisolver(child, depth + 1); //recursive call to access all the nodes of the tree
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] arr = new int[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(values[i]);
    }

    Node root = construct(arr);

    //assigning intial value to static members (which are allocated in heap memory)
    size = 0;
    height = 0;
    min = Integer.MAX_VALUE;
    max = Integer.MIN_VALUE;

    multisolver(root, 0);

    System.out.println("Size = " + size);
    System.out.println("Max = " + max);
    System.out.println("Min = " + min);
    System.out.println("Height = " + height);
  }

}
