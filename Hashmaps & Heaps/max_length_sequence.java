/*
DSA FOUNDATIONS - Hashmaps and Heaps                                          Date:11-Dec-2020       

1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the longest sequence of consecutive elements in the array (ignoring duplicates).

Note -> In case there are two sequences of equal length (and they are also the longest), then print the one for which the starting point of which occurs first in the array.
*/

import java.io.*;
import java.util.*;

public class Main{

public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt(); // size of the array
    
    int[] arr = new int[n]; // taking the input of the array
    for(int i=0; i<arr.length; i++)
        arr[i] = scn.nextInt();
        
    HashMap<Integer, Boolean> hm = new HashMap<>();
    
    for(int key : arr) 
        hm.put(key, true); // by default marks all the elements of the array as true assuming that all the elements are the starting of the sequence
    
    for(int key : arr) {
        if(hm.containsKey(key - 1)) // if the value 1 less than the passed value is present in the hashmap 
            hm.put(key, false); // make it false as it cannot be the start of the sequence 
    }
    
    int maxLen = 0, maxStartPt = 0;
    
    for(int key : arr) {
        if(hm.get(key) == true) { // only work for those elements which are the starting of the sequence
            int tempLen = 1, tempStartPt = key;
            
            while(hm.containsKey(tempStartPt + tempLen)) { // calculate the length of each subsequence
                tempLen++;
            }
            
            if(tempLen > maxLen) { // compare with the length of prev sequence
                maxLen = tempLen;
                maxStartPt = tempStartPt;
            }
        }
    }
    for(int i=0; i<maxLen; i++)
        System.out.println(maxStartPt + i);
 }

}