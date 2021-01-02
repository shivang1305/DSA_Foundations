/*
    DSA FOUNDATIONS - Hashmaps and Heaps                                            Date: 10-Dec-2020       
*/

import java.util.*;

public class Main{

public static void main(String[] args) {
    
    // all the methods of hashmap takes O(1) time i.e. in constant time
    
    HashMap<String, Integer> hm = new HashMap<>(); // declaring the hashmap
    
    // inserting the data into hashmap
    hm.put("India", 150);
    hm.put("China", 200);
    hm.put("Pakistan", 40);
    hm.put("USA", 20);
    hm.put("UK", 15);
    
    // printing the hashmap
    System.out.println(hm); // order of printing the values of hashmap is randomv (not in our control)
    
    hm.put("Bangladesh", 10); // adds new value to the hashmap if called with unique key
    hm.put("USA", 25); // updates the value of already present key in hashmap
    
    System.out.println(hm);
    
    // get() of hashmap
    System.out.println(hm.get("India")); // returns the value if the key is present in the hashmap
    System.out.println(hm.get("Austrialia")); // returns null if the key is not present in the hashmap
    
    // containsKey() method
    System.out.println(hm.containsKey("India")); // returns true if the key is present in the hashmap
    System.out.println(hm.containsKey("Austrailia")); // returns false of the key is not present in the hashmap
    
    Set<String> s = hm.keySet(); // keySet() method returns the list of all the keys in the hashmap
    System.out.println(s);
    
    // traversing through the hashmap
    for(String key: hm.keySet()) {
        Integer val = hm.get(key);
        System.out.println(key + " -> " + val);
    }
 }
}