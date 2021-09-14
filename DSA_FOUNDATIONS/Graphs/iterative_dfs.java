/*
    DSA Foundations - Graphs                                                              Date: 30-Dec-2020

1. You are given a graph, and a source vertex.
2. You are required to do a iterative depth first traversal and print which vertex is reached via which 
     path, starting from the source.

Note -> For output, check the sample output and question video. Iterative depth first traversal 
        should mimic "Reverse preorder" i.e. nbr with highest value should be visited first and 
        should be printed on the way down in recursion.

*/  


// Iterative DFS is almost same as BFS algo with stack instead of queue, it will run reverse euler which will print the DFS rather than BFS of the graph

import java.util.*;

public class iterative_dfs {
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

    static class Pair {
        int v;
        String psf;

        Pair(int v, String psf) {
            this.v = v;
            this.psf = psf;
        }
    }

    public static void iterativeDFS(ArrayList<Edge>[] graph, int src, boolean[] visited) { 
        Stack<Pair> st = new Stack<>();
        st.push(new Pair(src, src + ""));
        
        while(st.size() > 0) {
            // remove 
            Pair p = st.pop();
            
            if(visited[p.v] == false) {
                visited[p.v] = true; // mark *
                
                System.out.println(p.v + "@" + p.psf); // work
            }
            
            for(Edge e : graph[p.v]) {
                if(visited[e.nbr] == false)
                    st.push(new Pair(e.nbr, p.psf + e.nbr)); // add *
            }
        }
    }
}


// Iterative DFS saves memory in case of many vertices in the graph (no of vertices > 100000) stack.overflow.error will come in case of recursive DFS but in case of iterative approach we create the memory stack in the heap instead of stack calls which can take only limited calls. So we store only one object of the stack in the stack calls of the manually created stack in the heap 