/*
    DSA Foundations - Graphs                                                 Date: 18-Dec-2020

1. You are given a graph, a source vertex and a destination vertex.
2. You are required to find and print all paths between source and destination. Print 
     them in lexicographical order.
    
    E.g. Check the following paths
             012546
             01256
             032546
             03256

    The lexicographically smaller path is printed first.
*/

import java.util.*;

public class all_paths {
  static class Edge {
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt) {
      this.src = src;
      this.nbr = nbr;
      this.wt = wt;
   }
  }

  // String psf = "";
  // psf += src;

  public static void allPaths(ArrayList<ArrayList<Integer>> graph, int src, int dest, boolean[] visited, String psf) {
    if(src == dest) { // base case
      System.out.println(psf);
      return;
    }
    
    visited[src] = true; // marking the visited vertex to avoid the viscious cycle
    for(int e : graph.get(src)) {
        if(visited[e] == false) {
            allPaths(graph, e, dest, visited, psf + e); // recursive call
      }
    }
    visited[src] = false; // unmarking the vertex so that more paths can also be explored
 }
}

