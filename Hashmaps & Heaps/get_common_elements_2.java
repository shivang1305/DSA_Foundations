/*
DSA FOUNDATIONS - Hashmaps and Heaps                                          Date:10-Dec-2020       

1. You are given a number n1, representing the size of array a1.
2. You are given n1 numbers, representing elements of array a1.
3. You are given a number n2, representing the size of array a2.
4. You are given n2 numbers, representing elements of array a2.
5. You are required to find the intersection of a1 and a2. To get an idea check the example below:
 
if a1 -> 1 1 2 2 2 3 5
and a2 -> 1 1 1 2 2 4 5
intersection is -> 1 1 2 2 5
*/


import java.io.*;
import java.util.*;

public class Main{

public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    
    // taking input from the user
    int n1 = scn.nextInt();
    int[] a1 = new int[n1]; 
    for(int i = 0; i < a1.length; i++)
        a1[i] = scn.nextInt();
    
    int n2 = scn.nextInt();
    int[] a2 = new int[n2];
    for(int i = 0; i < a2.length; i++)
        a2[i] = scn.nextInt();
        
    HashMap<Integer, Integer> hm = new HashMap<>();
    
    // making the freq map 
    for(int val : a1) {
        if(hm.containsKey(val)) {
            int nf = hm.get(val) + 1;
            hm.put(val, nf);
        }
        else 
            hm.put(val, 1);
    }
    
    // traversing through the values of second array and checking for them in the hashmap
    for(int key : a2) {
        if(hm.containsKey(key) && hm.get(key) != 0) { // printing only the elements whose freq are not equal to zero
            System.out.println(key);
            int nf = hm.get(key) - 1; // decreasing the freq of the element
            hm.put(key, nf); // pushing the element into the hashmap with new freq
        }
    }
        
 }

}