/*
DSA FOUNDATIONS - Hashmaps and Heaps                                                Date:15-Dec-2020       

1. You are required to complete the code of our Hashmap class. Please watch the question video carefully. The theoretical details of required functionality is explained in detail there. Implement the functions to achieve what is explained in the theoretical discussion in question video.
2. Input and Output is managed for you.
*/


public static class HashMap<K, V> { // K, V can be of any datatype, this is called generic support to HashMap
    private class HMNode {
      K key;
      V value;

      HMNode(K key, V value) {
        this.key = key;
        this.value = value;
      }
    }

    private int size; // n
    private LinkedList<HMNode>[] buckets; // N = buckets.length

    public HashMap() {
      initbuckets(4); // constant threshold value which should always be greater than lambda
      size = 0;
    }

    private void initbuckets(int N) {
      buckets = new LinkedList[N];
      for (int bi = 0; bi < buckets.length; bi++) {
        buckets[bi] = new LinkedList<>();
      }
    }
    
    private int hashFunc(K key) {
        int hc = key.hashCode(); // inbuilt function in java that returns some integer against the valid key 
        return Math.abs(hc) % buckets.length;
    }
    
    private int getIndexInBucket(K key, int bi) {
        int di = 0;
        for(HMNode node : buckets[bi]) { // search in the given bucket by hash function only
            if(node.key.equals(key))
                return di;
            di++;
        }
        return -1; // if the given key is not found in the bucket
    }
 
    public void put(K key, V value) throws Exception {
      int bi = hashFunc(key);
      int di = getIndexInBucket(key, bi);
      
      if(di != -1) { // updation - update the value of already existing key in the hashmap
          HMNode node = buckets[bi].get(di);
          node.value = value;
      }
      else { // insertion - insert a new val or node since the key is unique and it is not present in the hashmap
          HMNode node = new HMNode(key, value);
          buckets[bi].add(node);
          size++;
      }
      
      double lambda = size * 1.0 / buckets.length;
      if(lambda > 2.0)
        rehash();
    }
    
    private void rehash() throws Exception {
        LinkedList<HMNode>[] oldBuckets = buckets; // create an old bucket array and transfer the data of buckets into this array
        
        initbuckets(oldBuckets.length * 2); // resize the buckets array with twice the older size
        size = 0;
        
        for(int i = 0; i < oldBuckets.length; i++) { // transfer the elements from olf buckets array to new buckets array, their position may be same or different depending upon the hashcode value 
            for(HMNode node : oldBuckets[i]) 
                put(node.key, node.value);
        }
        
        // this whole process is called rehashing
    }

    public V get(K key) throws Exception {
      int bi = hashFunc(key);
      int di = getIndexInBucket(key, bi);
      
      if(di != -1) { // return the value of the node whose key is passed
          HMNode node = buckets[bi].get(di);
          return node.value;
      }
      else  // since an invalid key is passed which is not present in the hashmap 
          return null;
    }

    public boolean containsKey(K key) {
      int bi = hashFunc(key);
      int di = getIndexInBucket(key, bi);
      
      if(di != -1)  // key is present
          return true;
      else  // since an invalid key is passed which is not present in the hashmap 
          return false;
    }

    public V remove(K key) throws Exception {
      int bi = hashFunc(key);
      int di = getIndexInBucket(key, bi);
      
      if(di != -1) { // return the value of the node whose key is passed
          HMNode node = buckets[bi].remove(di);
          size--;
          return node.value;
      }
      else  // since an invalid key is passed which is not present in the hashmap 
          return null;
    }

    public ArrayList<K> keyset() throws Exception {
      ArrayList<K> keys = new ArrayList<>();
      for(int i = 0; i < buckets.length; i++) {
          for(HMNode node : buckets[i])
            keys.add(node.key);
      }
      return keys;
    }

    public int size() {
      return size;
    }

   public void display() {
      System.out.println("Display Begins");
      for (int bi = 0; bi < buckets.length; bi++) {
        System.out.print("Bucket" + bi + " ");
        for (HMNode node : buckets[bi]) {
          System.out.print( node.key + "@" + node.value + " ");
        }
        System.out.println(".");
      }
      System.out.println("Display Ends");
  }
}