/*
DSA FOUNDATIONS - Hashmaps and Heaps                                                Date:13-Dec-2020       

1. You are given a list of lists, where each list is sorted.
2. You are required to complete the body of mergeKSortedLists function. The function is expected to merge k sorted lists to create one sorted list.
*/

public static class Pair implements Comparable<Pair> { // we have implemented this interface because we cannot directly compare the values of two different objects
       int dataIndex, listIndex, val;
       
       Pair(int dataIndex, int listIndex, int val) {
           this.dataIndex = dataIndex;
           this.listIndex = listIndex;
           this.val = val;
       }
       
       // since we have implemented Comparable interface so we have to write compareTo()
       public int compareTo(Pair p) {
           return this.val - p.val; // it returns negative value if this object's value ios greater than p's value
       }
}
        
public static ArrayList<Integer> mergeKSortedLists(ArrayList<ArrayList<Integer>> lists){
    ArrayList<Integer> rv = new ArrayList<>();
      
    PriorityQueue<Pair> pq = new PriorityQueue<>();
      
    // it adds the first element from every list into priority queue
    for(int i = 0; i < lists.size(); i++) {
        Pair p = new Pair(0, i, lists.get(i).get(0));
        pq.add(p);
    }
      
    while(pq.size() > 0) {
        Pair p = pq.remove(); // removes the smallest element from the priority queue
        rv.add(p.val); // adds the removed element into the final sorted list
        p.dataIndex++; // increases the data index of the list only from which element is inserted into the list
          
        if(p.dataIndex < lists.get(p.listIndex).size()) { // checks that there are elements left in that list
            p.val = lists.get(p.listIndex).get(p.dataIndex); // changes the value of the pair object
            pq.add(p); // adds new pair object value into priority queue
        }
    }
      
    return rv; // returns the final list which is sorted
}