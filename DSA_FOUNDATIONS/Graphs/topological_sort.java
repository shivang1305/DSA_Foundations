/*
    DSA Foundations - Graphs                                                              Date: 30-Dec-2020

1. You are given a directed acyclic graph. The vertices represent tasks and edges represent 
    dependencies between tasks.
2. You are required to find and print the order in which tasks could be done. The task that should be 
    done at last should be printed first and the task which should be done first should be printed last. 
    This is called topological sort. Check out the question video for details.

Topological sort -> A permutation of vertices for a directed acyclic graph is called topological sort if 
                    for all directed edges uv, u appears before v in the graph

*/  

import java.util.*;

public class topological_sort {
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
    
    public static void topologicalSort(ArrayList<Edge>[] graph, int src, boolean[] visited, Stack<Integer> st) {
        visited[src] = true; // visit the current vertex
        
        for(Edge e : graph[src]) { // adding the neigbours to the DFS tree 
            if(visited[e.nbr] == false)
                topologicalSort(graph, e.nbr, visited, st);
        }
        
        st.push(src); // adding the elements into the stack in the post order of DFS traversal which gives us the flow of the work
    }
}

