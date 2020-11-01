/*
                                                                                  Date: 16-Oct-2020
  Swapping the data values of the nodes without breaking the links.(Recursively)
*/

public void reverseDRHelper(Node right, int floor) {
  if(right == null)
    return;

  reverseDRHelper(right.next, floor+1); //recursive call

  if(floor >= size/2) { //to check that swapping occurs till the mid of the list
    //swapping the data of right and left pointer
    int temp = right.data;
    right.data = leftPtr.data;
    leftPtr.data = temp;

    leftPtr = leftPtr.next; //moving leftPtr forward in the heap
  }
}

Node leftPtr; //leftPtr is assigned into heap

public void reverseDR() {
  leftPtr = head;
  reverseDRHelper(head, 0);
}
