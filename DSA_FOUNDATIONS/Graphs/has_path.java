/*
    DSA Foundations - Graphs                                                 Date: 17-Dec-2020

1. You are given a graph, a src vertex and a destination vertex.
2. You are required to find if a path exists between src and dest. If it does, print true 
   otherwise print false.
*/

import java.util.*;

public class has_path {
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

  // DFS algo
  public static boolean hasPath(ArrayList<Edge>[] graph, int src, int dest, boolean[] visited) {
    if(src == dest) // base case 
      return true;
      
    visited[src] = true; // not to repeat the visited neighbours to avoid viscious cycle of repetition
    for(Edge edge : graph[src]) {
        if(visited[edge.nbr] == false) { // for only non-visited neighbours
            boolean isPath = hasPath(graph, edge.nbr, dest, visited); // faith
            
            if(isPath == true) // expectation
              return true;
        }
    }
    
    return false;
 }
}
