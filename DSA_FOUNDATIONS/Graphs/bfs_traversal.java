/*
    DSA Foundations - Graphs                                                              Date: 22-Dec-2020

1. You are given a graph, and a src vertex.
2. You are required to do a breadth first traversal and print which vertex is reached via which path, 
     starting from the src.
*/ 

import java.io.*;
import java.util.*;

public class bfs_traversal {
   static class Edge {
      int src;
      int nbr;

      Edge(int src, int nbr) {
         this.src = src;
         this.nbr = nbr;
      }
   }
   
   static class Pair {
       int src;
       String psf;
       
       Pair(int src, String psf) {
           this.src = src;
           this.psf = psf;
       }
   }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         graph[v1].add(new Edge(v1, v2));
         graph[v2].add(new Edge(v2, v1));
      }

      int src = Integer.parseInt(br.readLine());

      ArrayDeque<Pair> que = new ArrayDeque<>();
      que.add(new Pair(src, src + ""));
      
      boolean[] visited = new boolean[vtces];
      
      while(que.size() > 0) {
          // remove mark* work add*
          Pair p = que.removeFirst(); // remove the first element from the queue
          
          // marked the vertex if not marked
          if(visited[p.src] == false) {
              visited[p.src] = true;
              System.out.println(p.src + "@" + p.psf); // print the result
          }
          
          // explore the neighbours of the removed vertex from the queue
          for(Edge e : graph[p.src]) {
              if(visited[e.nbr] == false) {
                  que.add(new Pair(e.nbr, p.psf + e.nbr)); // add all the unvisited neighbours to the queue
              }
          }
      }

    /* BFS Without using Pair class */
    
    // List<Integer> bfs = new ArrayList<>();
    // ArrayDeque<Integer> que = new ArrayDeque<>();
    // que.add(src);

    // while(!que.isEmpty()) {
    //     Integer ele = que.removeFirst();

    //     if(!visited[ele]) {
    //         visited[ele] = true; // mark the curr node of graph
    //         bfs.add(ele);
            
    //         for(Edge e : graph[ele]) {
    //             if(!visited[e.nbr])
    //             que.add(e.nbr);
    //         }
    //     }
    // }
   }
}