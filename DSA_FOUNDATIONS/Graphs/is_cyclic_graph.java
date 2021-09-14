/*
    DSA Foundations - Graphs                                                              Date: 23-Dec-2020

1. You are given a graph.
2. You are required to find and print if the graph is cyclic.
*/ 

import java.util.*;

public class is_cyclic_graph {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int vtces = scn.nextInt();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
        for (int i = 0; i < vtces; i++) 
            adj.add(new ArrayList<>());
        

        int edges = scn.nextInt();
        for (int i = 0; i < edges; i++) {
            String word = scn.next();
            String[] parts = word.split(" ");
            int u = Integer.parseInt(parts[0]);
            int v = Integer.parseInt(parts[1]);
            
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        scn.close();

        System.out.println(isCycle(vtces, adj));
    }
    
    // Function to detect cycle in an undirected graph.
    public static boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V];
        
        for(int v = 0; v < V; v++) { // every unvisited vertex will get a chance as source to do the bfs traversal so that if the graph is given in the components then also we can check for cycles
            if(visited[v] == false) {
                boolean cycle = isCyclicDFS(adj, v, -1, visited);
                if(cycle == true) 
                    return true;
            }
        }        
        return false;
    }
    
    // BFS Algo
    public static boolean isCyclicBFS(ArrayList<ArrayList<Integer>> adj, int src, boolean[] visited) {
        ArrayDeque<Integer> que = new ArrayDeque<>();
        que.add(src);
        
        while(que.size() > 0) {
            int rem = que.removeFirst(); // remove
            
            if(visited[rem] == true) // when the curr node is already marked as visited
                return true; // that means there exists a cycle
            
            visited[rem] = true; // mark
            
            for(int e : adj.get(rem)) { 
                if(visited[e] == false) // if one vertex is visited more than once in a bfs traversal of the graph then there is a cycle in the graph
                    que.add(e); // add 
            }
            
        }
        return false;
    }

    // Time complexity = O(V + E)
    // Space complexity = O(V)
    
    // DFS Algo
    public static boolean isCyclicDFS(ArrayList<ArrayList<Integer>> adj, int src, int par, boolean[] visited) {
        if(visited[src] == true)
            return true;

        visited[src] = true;

        for(int e : adj.get(src)) {
            if(e != par) {
                boolean ans = isCyclicDFS(adj, e, src, visited);
                if(ans)
                    return true;
            }
        }
        return false;
    }

    // Time complexity = O(V + E)
    // Space complexity = O(V)
    // Auxillary(Recursive) Space = O(V)
}

    