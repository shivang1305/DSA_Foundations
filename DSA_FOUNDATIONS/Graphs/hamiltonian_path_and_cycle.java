/*
    DSA Foundations - Graphs                                                 Date: 22-Dec-2020

1. You are given a graph and a src vertex.
2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and paths with a "."

Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle if there is an edge between first and last vertex.
Note -> Print in lexicographically increasing order.
*/  

import java.util.*;

public class hamiltonian_path_and_cycle {
    static class Edge {
        int src;
        int nbr;

        Edge(int src, int nbr) {
            this.src = src;
            this.nbr = nbr;
        }
    }


    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int vtces = scn.nextInt();
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        
        for (int i = 0; i < vtces; i++) 
            graph[i] = new ArrayList<>();
        

        int edges = scn.nextInt();
        for (int i = 0; i < edges; i++) {
            String word = scn.next();
            String[] parts = word.split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            graph[v1].add(new Edge(v1, v2));
            graph[v2].add(new Edge(v2, v1));
        }

        int src = scn.nextInt();
        int orignalSrc = src;

        scn.close();
            
        HashSet<Integer> visited = new HashSet<>();
        hamiltonianPathAndCycle(vtces, graph, src, visited, src + "", orignalSrc);
    }

    //DFS Algo
    public static void hamiltonianPathAndCycle(int vtces, ArrayList<Edge>[] graph, int src, HashSet<Integer> visited, String psf, int orignalSrc) {
        // base case
        // since visited hashset is taking the values which we have visited before this one but psf is taking the value of vertex uptill now so that's why there is a gap of difference 1 between the comparing lengths
        if(visited.size() == vtces) {
            System.out.print(psf);
            
            boolean isCycle = false;
            for(Edge e : graph[src]) {
                if(e.nbr == orignalSrc)
                    isCycle = true;
            }
            
            if(isCycle == true) 
                System.out.println("*");
            else
                System.out.println(".");
        }   
        
        visited.add(src); // mark visited
        for(Edge e : graph[src]) { // nbrs loop
            if(visited.contains(e.nbr) == false)
                hamiltonianPathAndCycle(vtces, graph, e.nbr, visited, psf + e.nbr, orignalSrc);
        }
        visited.remove(src);
    }

    // DFS/ BFS : O(V + E) = O(n^2) 
}



