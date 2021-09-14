/*
    DSA Foundations - Graphs                                                              Date: 23-Dec-2020

1. You are given a graph.
2. You are required to find and print if the graph is bipartite

Note -> A graph is called bipartite if it is possible to split it's vertices in two sets of mutually 
        exclusive and exhaustive vertices such that all edges are across sets.
*/     

import java.util.*;
    
public class is_bipartite_graph {
    static class Pair {
        int vertex;
        String path;
        int level;
        
        Pair(int vertex, String path, int level) {
            this.vertex = vertex;
            this.path = path;
            this.level = level;
        }
    }
    
    public static boolean isBipartite(int[][] edges) {
        // creation of graph
        int n = edges.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
        for(int i = 0; i < n; i++)
            adj.add(new ArrayList<>());
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < edges[i].length; j++) 
                adj.get(i).add(edges[i][j]);
        }
        
        return isBipartite(n, adj);
    }
    
    public static boolean isBipartite(int V, ArrayList<ArrayList<Integer>>adj)
    {
        int[] visited = new int[V]; // here in the visited array we will store at which level the curr node of the graph is visited
        Arrays.fill(visited, -1); // -1 represents that the node is unvisited
        
        for(int v = 0; v < V; v++) { // check for all nodes of graph so that even if the graph is in components, we are able to find out bipartiteness
            if(visited[v] == -1) {
                boolean ans = isBipartiteDFS(adj, v, -1, visited, 0);
                if(!ans) // if any one component is not bipartite
                    return false;
            }
        }
        return true; // if all the components are bipartite
    }
    
    // BFS Algo
    private static boolean isBipartiteBFS(ArrayList<ArrayList<Integer>>adj, int src, int[] visited) {
        ArrayDeque<Pair> que = new ArrayDeque<>();
        que.add(new Pair(src, "" + src, 0));
        
        while(!que.isEmpty()) {
            Pair p = que.removeFirst();
            
            if(visited[p.vertex] != -1) {
                if(p.level != visited[p.vertex])
                    return false;
            }
            
            visited[p.vertex] = p.level;
            
            for(int e : adj.get(p.vertex)) {
                if(visited[e] == -1) 
                    que.add(new Pair(e, p.path + e, p.level + 1));
            }
        }
        return true;
    }

    // Time complexity = O(V + E)
    // Space complexity = O(V)
    
    // DFS Algo
    public static boolean isBipartiteDFS(ArrayList<ArrayList<Integer>>adj, int src, int par, int[] visited, int level) {
        if(visited[src] != -1) {
            if(visited[src] != level)
                return false;
        }

        visited[src] = level;

        for(int e : adj.get(src)) {
            if(e != par) {
                boolean ans = isBipartiteDFS(adj, e, src, visited, level + 1);
                if(!ans)
                    return false;
            }
        }
        return true;
    }

    // Time complexity = O(V + E)
    // Space complexity = O(V)
    // Auxillary(Recursive) Space = O(V)
}