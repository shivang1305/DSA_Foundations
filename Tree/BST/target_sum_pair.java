/*
    DSA Foundations - Binary Search Tree                                           Date: 09-Dec-2020

1. You are given a partially written BST class.
2. You are given a value. You are required to print all pair of nodes which add up to the given value. Make sure all pairs print the smaller value first and avoid duplicacies. Make sure to print the pairs in increasing order. Use the question video to gain clarity.
3. Input and Output is managed for you. 
*/ 

/* Approach 1 - Using find function in inorder traversal */

public static boolean find(Node node, int val) {
    // base case
    if(node == null)
      return false;
  
    // faith
    if(node.data > val)
      return find(node.left, val);
    if(node.data < val)
      return find(node.right, val);
      
    return true;
}

public static void targetSumPair(Node root, Node node, int target) {
    // base case
    if(node == null)
      return;
      
    // faith (left call)
    targetSumPair(root, node.left, target);
    
    // inorder space complexity = O(n) to traverse all the elements
    int complementVal = target - node.data;
    if(complementVal > node.data) {
        if(find(root, complementVal) == true) // time complexity = O(n.logn); logn = find(), n = targetSumPair() to inorder traverse the tree
          System.out.println(node.data + " " + complementVal);
    }
    
    // faith (right call)
    targetSumPair(root, node.right, target);
}


/* Approach 2 - Using arraylist */
// filling the arraylist and performing the target sum pair operation on the arraylist

public static void fillList(Node root, ArrayList<Integer> arr) { // space complexity = O(n)
    // base case
    if(node == null)
        return;
    
    // faith
    fillList(node.left, arr);

    // expectation
    arr.add(node.data);

    fillList(node.right, arr);
}

public static void main(String[] args) {
    ArrayList<Integer> list = new ArrayList<>();
    fillList(root, list);
    
    int li = 0;
    int ri = list.size() - 1;
    
    // time complexity = O(n)
    while(li < ri) {
        int leftVal = list.get(li);
        int rightVal = list.get(ri);
        
        if(leftVal + rightVal > data)
            ri--; // move the right index only
        else if(leftVal + rightVal < data)
            li++; // move the left index only
        else {
            System.out.println(leftVal + " " + rightVal);
            // move both the indices
            li++;
            ri--;
        }
    }
}
    
/* Approach 3 - Using left and right approach same as in arraylist but obtaining the left from normal inorder traversal and right from reverse inorder traversal */
    
  // pair class
  public static class ITPair {
    Node node;
    int state = 0;
    
    // parameterized constructor
    ITPair(Node node, int state) {
        this.node = node;
        this.state = state;
    }
}

// main aproach method
public static void bestApproach(Node node, int tar) {
    Stack<ITPair> leftStack = new Stack<>();
    Stack<ITPair> rightStack = new Stack<>();
    
    leftStack.push(new ITPair(node, 0));
    rightStack.push(new ITPair(node, 0));
    
    Node leftTrav = nextNodeFromNormalInorder(leftStack);
    Node rightTrav = nextNodeFromReverseInorder(rightStack);
    
    while(leftTrav.data < rightTrav.data) {
        if(leftTrav.data + rightTrav.data < tar) 
          leftTrav = nextNodeFromNormalInorder(leftStack);
        
        else if(leftTrav.data + rightTrav.data > tar)
          rightTrav = nextNodeFromReverseInorder(rightStack);
          
        else {
            System.out.println(leftTrav.data + " " + rightTrav.data);
            
            leftTrav = nextNodeFromNormalInorder(leftStack);
            rightTrav = nextNodeFromReverseInorder(rightStack);
        }
    }
}

// helper methods

// normal inorder traversal (increasing order will give leftTrav)
public static Node nextNodeFromNormalInorder(Stack<ITPair> st) {
    while(st.size() > 0) {
        ITPair top = st.peek();
        if(top.state == 0) { // preorder
            if(top.node.left != null)
              st.push(new ITPair(top.node.left, 0));
            top.state++;
        }
        else if(top.state == 1) { // inorder
            if(top.node.right != null)
              st.push(new ITPair(top.node.right, 0));
            top.state++;
            
            return top.node;
        }
        else // postorder
          st.pop();
    }
    
    return null;
}

// reverse inorder traversal (decresing order will give the rightTrav)
public static Node nextNodeFromReverseInorder(Stack<ITPair> st) {
    while(st.size() > 0) {
        ITPair top = st.peek();
        if(top.state == 0) { // preorder
            if(top.node.right != null)
              st.push(new ITPair(top.node.right, 0));
            top.state++;
        }
        else if(top.state == 1) { // inorder
            if(top.node.left != null)
              st.push(new ITPair(top.node.left, 0));
            top.state++;
            
            return top.node;
        }
        else // postorder
          st.pop();
    }
    
    return null;
}