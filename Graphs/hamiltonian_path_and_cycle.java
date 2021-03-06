/*
    DSA Foundations - Graphs                                                              Date: 22-Dec-2020

1. You are given a graph and a src vertex.
2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and paths with a "."

Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle if there is an edge between first and last vertex.
Note -> Print in lexicographically increasing order.
*/  

int src = Integer.parseInt(br.readLine());
int orignalSrc = src;
      
HashSet<Integer> visited = new HashSet<>();
hamiltonianPathAndCycle(graph, src, visited, src + "", orignalSrc);

//DFS Algo
public static void hamiltonianPathAndCycle(ArrayList<Edge>[] graph, int src, HashSet<Integer> visited,      String psf, int orignalSrc) {
    // base case
    // since visited hashset is taking the values which we have visited before this one but psf is taking the value of vertex uptill now so that's why there is a gap of difference 1 between the comparing lengths
    if(visited.size() == graph.length - 1) {
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
    
    visited.add(src);
    for(Edge e : graph[src]) {
        if(visited.contains(e.nbr) == false)
         hamiltonianPathAndCycle(graph, e.nbr, visited, psf + e.nbr, orignalSrc);
    }
    visited.remove(src);
}