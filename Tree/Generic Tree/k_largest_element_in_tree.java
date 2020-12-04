/*                                                                                Date: 02-Nov-2020
1. You are given a partially written GenericTree class.
2. You are given a number k. You are required to find and print the kth largest value in the tree.
3. Input and Output is managed for you.
*/

  //k largest element in the tree will be the floor of the infinity value obtained k times in the tree
  public static int kthLargest(Node node, int k){
    floor = Integer.MIN_VALUE;
    int kMax = Integer.MAX_VALUE;

    //this loop will obtain the values of tree in decendig order k times
    for(int i=1; i<=k ; i++) {
        ceilAndFloor(node, kMax);
        kMax = floor;
        floor = Integer.MIN_VALUE; //setting floor to its orignal value
    }
    return kMax;
  }
