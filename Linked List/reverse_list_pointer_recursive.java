/*
                                                                                 Date : 15-Oct-2020
1. You are given a partially written LinkedList class.
2. You are required to complete the body of reversePR and reversePRHelper functions. The functions are expected to reverse the linked list by using recursion and changing the "next" data member of nodes.
3. Input and Output is managed for you.
*/


  private void reversePRHelper(Node node){
      if(node == null)
        return;

      reversePRHelper(node.next); //recursive call

      if(node != tail) //for all nodes except the last node of LL
        node.next.next = node; //breaks the forward link and makes a backward link
    }

    public void reversePR(){
      reversePRHelper(head);
      head.next = null;
      Node temp = head;
      head = tail;
      tail = temp;
    }
