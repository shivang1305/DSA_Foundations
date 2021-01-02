/*
    DSA FOUNDATIONS - Hashmaps and Heaps                                            Date: 10-Dec-2020       

1. You are given a string str.
2. You are required to find the character with maximum frequency.
*/

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // taking the string as input from the user
        Scanner sn = new Scanner(System.in);
        String str = sn.nextLine();
        
        // putting all the characters of the string into the hashmap
        HashMap<Character, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            
            if(hm.containsKey(ch)) { // when the key is already present
                int newFreq = hm.get(ch) + 1; // increasing the freq of the character
                hm.put(ch, newFreq); 
            }
            
            else // when the key is not present
                hm.put(str.charAt(i), 1);
        }
        
        char maxFreqChar = str.charAt(0); // taking the first character as max freq character in the starting 
        
        for(Character key: hm.keySet()) {
            if(hm.get(key) > hm.get(maxFreqChar)) // if we found that higher freq that our assumed character
                maxFreqChar = key; // then max freq character changes to the key
        }
        
        System.out.println(maxFreqChar);
    }

}