/*
DSA FOUNDATIONS - Hashmaps and Heaps                                                    Date:11-Dec-2020       

Introduction to Heap data structure which is implemented with the help of priority queue.
Priority queue arranges the data in the order of its priority and hence sorts the data accordingly.
*/

import java.util.*;

public class Main{

public static void main(String[] args) {
    PriorityQueue<Integer> pq = new PriorityQueue<>(); // by default the smallest value is given the highest priority 
    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); // to reverse the priority of the queue 
    
    int[] arr = {11, 5, 99, 3, 6, 9};
    
    // overall time complexity = O(nlogn)
    for(int val : arr) { // O(n)
        pq.add(val); // O(logn)
    }
    
    // overall time complexity = O(nlogn)
    while(pq.size() > 0) { // O(n)
        System.out.println(pq.peek());
        pq.remove(); // O(logn)
    }

 }
}