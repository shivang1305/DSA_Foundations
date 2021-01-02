/*
DSA FOUNDATIONS - Hashmaps and Heaps                                                    Date:11-Dec-2020       

1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are given a number k.
4. You are required to find and print the k largest elements of array in increasing order.
*/

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int[] arr = new int[n];

      for (int i = 0; i < n; i++) 
         arr[i] = Integer.parseInt(br.readLine());
      
      int k = Integer.parseInt(br.readLine());
      
      PriorityQueue<Integer> pq = new PriorityQueue<>();
      
      for(int i = 0; i < arr.length; i++) {
          if(i < k) // when the team has less than the required number of players
            pq.add(arr[i]); // all the incoming players are welcomed without looking at their skills
        
          else { // when the team has got more players than the required ones, this is the time when selection process begins
              if(pq.peek() < arr[i]) { // if the incoming player is better than the current worst player of the team
                  pq.remove(); // current worst player is removed
                  pq.add(arr[i]); // incoming player is added
              }
          }
      }
      
      while(pq.size() > 0) 
          System.out.println(pq.remove());
    }

}


// Space complexity = O(k) because there are never more than k elements in the priority queue
// Time Complexity = O(nlogk) n for the outer for loop which runs over the whole array and logk for removing and adding new elements to the priority queue.
