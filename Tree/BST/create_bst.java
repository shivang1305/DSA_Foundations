/*
    DSA Foundations - Binary Search Tree                                           Date: 07-Dec-2020

    Create a binary search tree from given array    
*/

public static Node construct(int[] arr, int lo, int hi) {
    // base case
    if(lo > hi)
        return null;
        
    int mid = (lo + hi)/2;
    int data = arr[mid];
    
    // faith
    Node leftChild = construct(arr, lo, mid-1);
    Node rightChild = construct(arr, mid+1, hi);
    
    //expectation
    Node node = new Node(data, leftChild, rightChild);
    
    return node;
  }
