/*
    DSA Foundations - Graphs                                                              Date: 19-Dec-2020

1. You are given a graph, a src vertex and a destination vertex.
2. You are give a number named "criteria" and a number "k".
3. You are required to find and print the values of 
    3.1 Smallest path and it's weight separated by an "@"
    3.2 Largest path and it's weight separated by an "@"
    3.3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
    3.4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
    3.5 Kth largest path and it's weight separated by an "@"
*/  

    import java.util.*;
   
public class multisolver_graph_paths {
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
        int wsf;
        String psf;
  
        Pair(int wsf, String psf){
           this.wsf = wsf;
           this.psf = psf;
        }
  
        public int compareTo(Pair o){
           return this.wsf - o.wsf;
        }
     }

    static String spath;
    static Integer spathwt = Integer.MAX_VALUE;
    static String lpath;
    static Integer lpathwt = Integer.MIN_VALUE;
    static String cpath;
    static Integer cpathwt = Integer.MAX_VALUE;
    static String fpath;
    static Integer fpathwt = Integer.MIN_VALUE;
    static PriorityQueue<Pair> pq = new PriorityQueue<>();
    
    public static void multisolver(ArrayList<Edge>[] graph, int src, int dest, boolean[] visited, int criteria, int k, String psf, int wsf) {
        // base case
        if(src == dest) {
            // solving the given cases 
            if(wsf < spathwt) { // for smallest path and weight
                spath = psf;
                spathwt = wsf;
            }
            
            if(wsf > lpathwt) { // for largest path and weight
                lpath = psf;
                lpathwt = wsf;
            }
            
            if(wsf > criteria && wsf < cpathwt) { // for ceil path as per given criteria
                cpath = psf;
                cpathwt = wsf;
            }
            
            if(wsf < criteria && wsf > fpathwt) { // for floor path as per given criteria
                fpath = psf;
                fpathwt = wsf;
            }
            
            if(pq.size() < k) // to obtain kth largest path
                pq.add(new Pair(wsf, psf));
            else {
                if(wsf > pq.peek().wsf) {
                    pq.remove();
                    pq.add(new Pair(wsf, psf));
                }
            }
            
            return;
        }
        
        visited[src] = true; // marking the edge
        for(Edge e : graph[src]) {
            if(visited[e.nbr] == false) {
                multisolver(graph, e.nbr, dest, visited, criteria, k, psf + e.nbr, wsf + e.wt);
            }
        }
        visited[src] = false; // unmarking the edge
    }
}
   
