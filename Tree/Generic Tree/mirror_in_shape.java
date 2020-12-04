/*                                                                                Date: 01-Nov-2020

Are the given trees mirror in shape of each other or not. Only consider the shape and not the data.

1. You are given a partially written GenericTree class.
2. You are required to complete the body of areMirror function. The function is expected to check if the two trees passed to it are mirror images of each other in shape (data not to be checked, just the shape of tree).
Note -> Watch the question video for clarity.
3. Input and Output is managed for you.
*/


  //similar approach to check the similar shape of the tree (prev question)
  public static boolean areMirror(Node n1, Node n2) {
    if(n1.children.size() != n2.children.size())
        return false;

    //i -> moving forward
    //j -> moving reverse
    for(int i=0, j=n2.children.size()-1; i<n1.children.size() && j>=0; i++, j--) {
        Node d1 = n1.children.get(i);
        Node d2 = n2.children.get(j);

        if(areMirror(d1, d2) == false)
            return false;
    }

    //complier reaches here only if all above conditions do not satisfy
    return true;
  }
