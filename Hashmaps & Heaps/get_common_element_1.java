/*
DSA FOUNDATIONS - Hashmaps and Heaps                                          Date:10-Dec-2020       

1. You are given a number n1, representing the size of array a1.
2. You are given n1 numbers, representing elements of array a1.
3. You are given a number n2, representing the size of array a2.
4. You are given n2 numbers, representing elements of array a2.
5. You are required to print all elements of a2 which are also present in a1 (in order of their occurence in a2). Make sure to not print duplicates (a2 may have same value present many times).
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
        if(hm.containsKey(key)) {
            System.out.println(key);
            hm.remove(key); // removing the once visited keys so that no duplicate element is printed
        }
    }
        
 }

}