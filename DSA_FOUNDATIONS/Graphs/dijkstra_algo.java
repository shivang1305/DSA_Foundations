/*
    DSA Foundations - Graphs                                                              Date: 30-Dec-2020

1. You are given a graph and a source vertex. The vertices represent cities and the edges represent 
    distance in kms.
2. You are required to find the shortest path to each city (in terms of kms) from the source city along 
    with the total distance on path from source to destinations.
*/  
import java.util.*;

public class dijkstra_algo {
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
        int v;
        String psf;
        int wsf;
        
        Pair(int v, String psf, int wsf) {
            this.v = v;
            this.psf = psf;
            this.wsf = wsf;
        }
        
        public int compareTo(Pair p) { // sorting in priority queue is done on the basis of weight so far 
            return this.wsf - p.wsf;
        }
    }
    
    
    // same BSF algo with priority queue
    public static void dijkstraAlgo(ArrayList<Edge>[] graph, int src, boolean[] visited) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(src, src + "", 0));
        
        while(pq.size() > 0) {
            Pair p = pq.remove(); // remove 
            
            if(visited[p.v] == false) { 
                visited[p.v] = true; // mark visited
                
                System.out.println(p.v + " via " + p.psf + " @ " + p.wsf); // work
            }
            
            for(Edge e : graph[p.v]) { 
                if(visited[e.nbr] == false) 
                    pq.add(new Pair(e.nbr, p.psf + e.nbr, p.wsf + e.wt)); // add in priority queue 
            }
        }
    }
}

