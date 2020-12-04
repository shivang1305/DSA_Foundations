/*                                                                               Date: 02-Nov-2020
1. You are given a partially written GenericTree class.
2. You are required to find the ceil and floor value of a given element. Use the "travel and change" strategy explained in the earlier video. The static properties - ceil and floor have been declared for you. You can declare more if you want. If the element is largest ceil will be largest integer value (32 bits), if element is smallest floor will be smallest integer value (32 bits). Watch the question video for clarity.
3. Input and Output is managed for you.
*/

static int ceil; //smallest among larger values
  static int floor;//largest among smaller values
  public static void ceilAndFloor(Node node, int data) {
    //preorder area
    if(node.data > data && node.data < ceil)
        ceil = node.data;
    else if(node.data < data && node.data > floor)
        floor = node.data;

    for(Node child: node.children)
        ceilAndFloor(child, data);
  }
