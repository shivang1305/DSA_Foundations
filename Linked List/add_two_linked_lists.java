/*                                                                                Date: 17-Oct-2020

1. You are given a partially written LinkedList class.
2. You are required to complete the body of addLinkedLists function. The function is passed two linked lists which represent two numbers - the first element is the most significant digit and the last element is the least significant digit. The function is expected to add the two linked list and return a new linked list.

The following approaches are not allowed :
    1. Don't reverse the linked lists in order to access them from least significant digit
     to most significant.
     2. Don't use arrays or explicit extra memory.
     3. Don't convert linked lists to number, add them up and convert the result back
     to a linked list.

Hint - You are expected to take help of recursion to access digits from least significant to most significant. You have to tackle the challenge of unequal size of lists and manage carry where required.
*/

public static int addTwoListsHelper(Node one, int pv1, Node two, int pv2, LinkedList res) {
        if(one == null && two == null) //base case of recursion
            return 0;

        int data;
        int c;

        if(pv1 > pv2) {
            c = addTwoListsHelper(one.next, pv1-1, two, pv2, res);
            data = one.data + c;
        }
        else if(pv1 < pv2) {
            c = addTwoListsHelper(one, pv1, two.next, pv2-1, res);
            data = two.data + c;
        }
        else {
            c = addTwoListsHelper(one.next, pv1-1, two.next, pv2-1, res);
            data = one.data + two.data + c;
        }

        int newData = data % 10;
        int newCarry = data / 10;

        res.addFirst(newData);

        return newCarry;
    }

    public static LinkedList addTwoLists(LinkedList one, LinkedList two) {
      LinkedList res = new LinkedList();

      int carry = addTwoListsHelper(one.head, one.size, two.head, two.size, res);
      if(carry > 0) //to resolve the final carry at the end
        res.addFirst(carry);

      return res;
    }
