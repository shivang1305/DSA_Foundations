/*
DSA FOUNDATIONS - Hashmaps and Heaps                                                Date:16-Dec-2020       

Generally the constructor of priority queue is of the order O(n.logn). Can you make a constructor of priority queue in linear time. 
*/

public PriorityQueue(int[] arr) {
    data = new ArrayList<>();
    
    /* Approach 1 - Calling upheapify method on each element to be added */
    // overall time complexity = O(n.logn)
    for(int val : arr) // O(n) 
        this.add(val); // O(logn), since upheapify method is being called on each element which is added
        
    /* Approach 2 - Calling downheapify method after adding all the elements to the arraylist */
    for(int val : arr) // O(n)
        data.add(val); //simply adding each element to the array without calling upheapify or downheapify method
        // Complete BST property is honoured but Heap order property is voilated
        
    for(int i = (data.size() - 1) / 2; i >= 0; i--) //reverse iterate the arraylist from the second last level and call downheapify method on each element 
        downHeapify(i); // O(logn)

    // Overall time complexity for this approach = O(n) + O(logn) = O(n) (better than O(n.logn))
}

public static void main(String[] args) throws Exception {
    int[] arr = {10, 2, 17, 3, 18, 9, 22};
    PriorityQueue pq = new PriorityQueue(arr); // calling the parameterized constructor
    
    while(pq.size() > 0) 
        System.out.println(pq.remove());
}