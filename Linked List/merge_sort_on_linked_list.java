/*
                                                                                 Date: 11-Oct-2020
1. You are given a partially written LinkedList class.
2. You are required to complete the body of mergeSort function. The function is static and is passed the head and tail of an unsorted list. The function is expected to return a new sorted list. The original list must not change.
3. Input and Output is managed for you.

Note - Watch the question video for theory of merge sort.
*/

public static LinkedList mergeTwoSortedLists(LinkedList l1, LinkedList l2) {
      LinkedList ml = new LinkedList();

      Node one = l1.head;
      Node two = l2.head;
      while (one != null && two != null) {
        if (one.data < two.data) {
          ml.addLast(one.data);
          one = one.next;
        } else {
          ml.addLast(two.data);
          two = two.next;
        }
      }

      while (one != null) {
        ml.addLast(one.data);
        one = one.next;
      }

      while (two != null) {
        ml.addLast(two.data);
        two = two.next;
      }

      return ml;
}

public static Node midList(Node head, Node tail) {
        Node fast = head;
        Node slow = head;

        while(fast != tail && fast.next != tail) {
            fast = fast.next.next;
            slow = slow.next;
        }

        return slow;
}

public static LinkedList mergeSort(Node head, Node tail){
      //base case
      if(head == tail) {
          //put that node into a new linked list and return
          LinkedList l = new LinkedList();
          l.addLast(head.data);
          return l;
      }

      Node mid = midList(head, tail); //to obtain the mid

      //recursive calls for breaking the linked list into smaller parts
      LinkedList l1 = mergeSort(head, mid);
      LinkedList l2 = mergeSort(mid.next, tail);

      //merging two sorted linked list
      LinkedList finalList = mergeTwoSortedLists(l1, l2);

      return finalList;

    }
