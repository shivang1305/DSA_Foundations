/*                                                                               Date: 19-Oct-2020
1. You are given a partially written GenericTree class.
2. You are required to complete the body of max function. The function is expected to find the node with maximum value and return it.
3. Input and Output is managed for you.
*/

public static int max(Node node) {
    int maxi = node.data;
    for(Node child : node.children) {
        int maxSubtree = max(child); //obtaining the max of child nodes i.e subtrees and compare it with itself
        maxi = Math.max(maxi, maxSubtree); //max of itself and children
    }

    return maxi;
  }
