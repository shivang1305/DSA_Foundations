/*                                                                               Date: 12-Oct-2020

1. You are given a partially written LinkedList class.
2. You are required to complete the body of oddEven function. The function is expected to tweak the list such that all odd values are followed by all even values. The relative order of elements should not change. Also, take care of the cases when there are no odd or no even elements. Make sure to properly set head, tail and size as the function will be tested by calling addFirst and addLast.
3. Input and Output is managed for you
*/

public void oddEven(){
      LinkedList lOdd = new LinkedList();
      LinkedList lEven = new LinkedList();

      while(this.size > 0) {
        int val = this.getFirst();
        this.removeFirst();

        if(val % 2 != 0)
          lOdd.addLast(val);
        else
          lEven.addLast(val);
      }

      if(lOdd.size > 0 && lEven.size > 0) {//merge both the lists
          lOdd.tail.next = lEven.head;
          this.head = lOdd.head; //setting tail to appropriate position
          this.tail = lEven.tail;
          this.size = lOdd.size + lEven.size;
      }
      else if(lOdd.size > 0) { //if there is no even element in the list
          this.head = lOdd.head;
          this.tail = lOdd.tail;
          this.size = lOdd.size;
      }
      else if(lEven.size > 0) { //if there is no odd element in the list
          this.head = lEven.head;
          this.tail = lEven.tail;
          this.size = lEven.size;
      }
    }
