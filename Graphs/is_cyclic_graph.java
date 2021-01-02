/*
    DSA Foundations - Graphs                                                              Date: 23-Dec-2020

1. You are given a graph.
2. You are required to find and print if the graph is cyclic.
*/ 

    boolean[] visited = new boolean[vtces];
    for(int v = 0; v < vtces; v++) { // every unvisited vertex will get a chance as source to do the bfs traversal so that if the graph is given in the components then also we can check for cycles
        if(visited[v] == false) {
            boolean cycle = isCyclic(graph, v, visited);
            if(cycle == true) {
                System.out.println(true);
                return;
            }
        }
    }        
    System.out.println(false);

    
    // BFS Algo
    public static boolean isCyclic(ArrayList<Edge>[] graph, int src, boolean[] visited) {
        ArrayDeque<Integer> que = new ArrayDeque<>();
        que.add(src);
        
        while(que.size() > 0) {
            int rem = que.removeFirst(); // remove
            
            if(visited[rem] == true) // mark *
                return true;
            visited[rem] = true;
            
            for(Edge e : graph[src]) { // add *
                if(visited[e.nbr] == false) // if one vertex is visited more than once in a bfs traversal of the graph then there is a cycle in the graph
                    que.add(e.nbr);
            }
            
        }
        
        return false;
    }