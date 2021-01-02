/*
    DSA Foundations - Graphs                                                              Date: 23-Dec-2020

1. You are given a graph.
2. You are required to find and print if the graph is bipartite

Note -> A graph is called bipartite if it is possible to split it's vertices in two sets of mutually 
        exclusive and exhaustive vertices such that all edges are across sets.
*/     
    
    int[] visited = new int[vtces];
    Arrays.fill(visited, -1); // fills all the values in the array with -1 value initially which represents that the current vertex is not visited
        
    for(int v = 0; v < vtces; v++) {
        if(visited[v] == -1) {
            boolean bipartite = isBipartite(graph, v, visited);
            if(bipartite == false) {
                System.out.println(false);
                return;
            }
        }
    }
        
    System.out.println(true);

    // BFS Algorithm
    public static boolean isBipartite(ArrayList<Edge>[] graph, int src, int[] visited) {
        ArrayDeque<Pair> que = new ArrayDeque<>();
        que.add(new Pair(src, 0));
        
        while(que.size() > 0) {
            Pair p = que.removeFirst();
            
            if(visited[p.vertex] != -1) { // check for the level if we found the cycle in the graph
                if(visited[p.vertex] != p.level)
                    return false;
            }
            else 
                visited[p.vertex] = p.level;
            
            for(Edge e : graph[p.vertex]) { 
                if(visited[e.nbr] == -1) 
                    que.add(new Pair(e.nbr, p.level + 1));
            }
        }
        
        return true;
    }