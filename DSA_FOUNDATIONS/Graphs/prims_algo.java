/*
    DSA Foundations - Graphs                                                              Date: 30-Dec-2020

1. You are given a graph and a source vertex. The vertices represent computers and the edges 
     represent length of LAN wire required to connect them.
2. You are required to find the minimum length of wire required to connect all PCs over a network. 
     Print the output in terms of which all PCs need to be connected, and the length of wire between 
     them.
*/  

import java.util.*;

public class prims_algo {

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

    static class Pair implements Comparable<Pair> {
        int v; // vertex
        int av; // acquiring vertex
        int wt; // weight of the edge
        
        Pair(int v, int av, int wt) {
            this.v = v;
            this.av = av;
            this.wt = wt;
        }
        
        public int compareTo(Pair p) {
            return this.wt - p.wt; // sorting in the priority queue is done on the basis of weights of the edge
        }
    }
    
    
    public static void primsAlgo(ArrayList<Edge>[] graph, int src, boolean[] visited) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(src, -1, 0)); // here -1 is the initial acquiring vertex which is assumed by us
        
        while(pq.size() > 0) {
            Pair p = pq.remove(); // remove
            
            if(visited[p.v] == false) { // mark *
                visited[p.v] = true;
                
                if(p.av != -1) // except for the first acquiring vertex which does not actually exists
                    System.out.println("[" + p.v + "-" + p.av + "@" + p.wt + "]"); // work
            }
            
            for(Edge e : graph[p.v]) { // add *
                if(visited[e.nbr] == false)
                    pq.add(new Pair(e.nbr, p.v, e.wt)); // same as dijkstra algo but the only difference is that in dijkstra algo we add the weights of the edges in each call and psf is also calculated but here we do not need to do that instead only current edge weight is passed in the call.
            }
        }
    }
}


