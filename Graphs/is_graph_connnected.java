/*
    DSA Foundations - Graphs                                                              Date: 20-Dec-2020

1. You are given a graph.
2. You are required to find and print if the graph is connected (there is a path from 
   every vertex to every other).
*/     
    
public static void main(String[] args){
    ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
    boolean[] visited = new boolean[vtces];
    
    for(int v = 0; v < vtces; v++) { // to give a chance to make a component tree for every vertex of the graph
        if(visited[v] == false) { // for unvisited vertex only
          ArrayList<Integer> comp = new ArrayList<>();
          calComponent(graph, v, comp, visited);
          comps.add(comp);
        }
    }

    System.out.println(comps.size() == 1); // the graph will be connected only if the size of components list is 1
}

// DFS Algo
public static void calComponent(ArrayList<Edge>[] graph, int src, ArrayList<Integer> comp, boolean[] visited) {
    visited[src] = true;
    comp.add(src);
    
    for(Edge edge: graph[src]) {
        if(visited[edge.nbr] == false)
          calComponent(graph, edge.nbr, comp, visited);
    }
}