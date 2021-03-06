/*
    DSA Foundations - Graphs                                                              Date: 18-Dec-2020

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

public static void allPaths(ArrayList<Edge>[] graph, int src, int dest, boolean[] visited, String psf) {
    if(src == dest) { // base case
      System.out.println(psf);
      return;
    }
    
    visited[src] = true; // marking the visited vertex to avoid the viscious cycle
    for(Edge edge : graph[src]) {
        if(visited[edge.nbr] == false) {
            allPaths(graph, edge.nbr, dest, visited, psf + edge.nbr); // recursive call
      }
    }
    visited[src] = false; // unmarking the vertex so that more paths can also be explored
 }