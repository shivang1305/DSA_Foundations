/*
    DSA Foundations - Graphs                                                              Date: 22-Dec-2020

1. You are given a number n (representing the number of students). Each student will have an id 
     from 0 to n - 1.
2. You are given a number k (representing the number of clubs)
3. In the next k lines, two numbers are given separated by a space. The numbers are ids of 
     students belonging to same club.
4. You have to find in how many ways can we select a pair of students such that both students are 
     from different clubs.
*/  


import java.io.*;
import java.util.*;

public class perfect_friends {
   
   public static class Edge {
       int vertex;
       int nbr;
       
       Edge(int vertex, int nbr) {
           this.vertex = vertex;
           this.nbr = nbr;
       }
   }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int n = Integer.parseInt(br.readLine()); // no of vertices or no of friends
      int k = Integer.parseInt(br.readLine()); // no of edges
      
      ArrayList<Edge>[] graph = new ArrayList[n];
      for(int v = 0; v < n; v++)
        graph[v] = new ArrayList<>(); // assigning empty arraylist to each vertex
        
      for(int e = 0; e < k; e++) {
          String line = br.readLine();
          String parts[] = line.split(" ");
          
          int v1 = Integer.parseInt(parts[0]);
          int v2 = Integer.parseInt(parts[1]);
          
          graph[v1].add(new Edge(v1, v2));
          graph[v2].add(new Edge(v2, v1));
      }
      
      ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
      boolean[] visited = new boolean[n];
      
      for(int v = 0; v < n; v++) {
          if(visited[v] == false) {
              ArrayList<Integer> comp = new ArrayList<>();
              calComponent(graph, v, visited, comp);
              comps.add(comp);
          }
      }
      
      int pairs = 0;
      
      for(int i = 0; i < comps.size(); i++) {
          for(int j = i + 1; j < comps.size(); j++) {
              int count = comps.get(i).size() * comps.get(j).size();
              pairs += count;
          }
      }
      
      System.out.println(pairs);
   }
   
   public static void calComponent(ArrayList<Edge>[] graph, int src, boolean[] visited, ArrayList<Integer> comp) {
       visited[src] = true;
       comp.add(src);
       
       for(Edge e : graph[src]) {
           if(visited[e.nbr] == false) 
               calComponent(graph, e.nbr, visited, comp);
       }
   }

}