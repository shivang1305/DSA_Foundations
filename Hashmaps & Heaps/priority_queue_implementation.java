/*
DSA FOUNDATIONS - Hashmaps and Heaps                                                Date:15-Dec-2020       

1. You are required to complete the code of our Priority Queue class using the heap data structure. Please watch the question video carefully. The theoretical details of required functionality is explained in detail there. Implement the functions to achieve what is explained in the theoretical discussion in question video.
2. Here is the list of functions that you are supposed to complete:
    2.1. add -> Should accept new data.
    2.2. remove -> Should remove and return smallest value, if available or print 
     "Underflow" otherwise and return -1.
     2.3. peek -> Should return smallest value, if available or print "Underflow" 
     otherwise and return -1.
     2.4. size -> Should return the number of elements available.
3. Input and Output is managed for you.
*/

// swap function O(1) i.e constant time 
private void swap(int i, int j) {
    int ith = data.get(i);
    int jth = data.get(j);
    
    data.set(i, jth);
    data.set(j, ith);
}

// O(1)
public void add(int val) {
  data.add(val); // adding the value in the last of already existing arraylist
  upHeapify(data.size() - 1);
}

//O(log n)
private void upHeapify(int idx) {
  // base case
  if(idx == 0) // index has reached upto root and cannot go beyond this
    return;
    
  int parentIdx = (idx - 1) / 2; // since it is a complete binary tree we can obtain parent index from the child index
  
  if(data.get(parentIdx) > data.get(idx)) {
      swap(parentIdx, idx); // swapping parent with child so that Heap order property is honoured
      upHeapify(parentIdx); // recursive calling 
  }
}

//O(1)
public int remove() {
  if(this.size() == 0) {
      System.out.println("Underflow");
      return -1;
  }
  
  swap(0, data.size() - 1); // move the highest priority element to the last of the arraylist
  int val = data.remove(data.size() - 1); // remove the element from the last of arraylist O(1)
  downHeapify(0); // move the swapped element to its proper position so that heap order property remains intact
  return val;
}

//O(log n)
private void downHeapify(int idx) {
    //obtaining left and right child index by complete binary tree property
    int leftIdx = 2 * idx + 1;
    int rightIdx = 2 * idx + 2;
    
    int minIdx = idx;
    
    // obtaining the min element from parent, left and right child and swapping
    if(leftIdx < data.size() && data.get(leftIdx) < data.get(minIdx))
        minIdx = leftIdx;
    
    if(rightIdx < data.size() && data.get(rightIdx) < data.get(minIdx))
        minIdx = rightIdx;
        
    if(minIdx != idx) {
        swap(idx, minIdx);
        downHeapify(minIdx); // recursive calling of down heapify
    }
}

//O(1)
public int peek() {
  if(this.size() == 0) {
      System.out.println("Underflow");
      return -1;
  }
  return data.get(0); // as per the heap order property the highest priority element will always be present at the first place in arraylist and at root of the tree
}

//O(1)
public int size() {
  return data.size();
}

// Overall time complexity for n elements will be O(n.logn)