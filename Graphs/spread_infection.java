/*
    DSA Foundations - Graphs                                                              Date: 23-Dec-2020

1. You are given a graph, representing people and their connectivity.
2. You are also given a src person (who got infected) and time t.
3. You are required to find how many people will get infected in time t, if the infection spreads to neighbors of infected person in 1 unit of time.
*/         
    
    int src = Integer.parseInt(br.readLine());
    int t = Integer.parseInt(br.readLine());

    boolean[] visited = new boolean[vtces];
    System.out.println(spreadInfection(graph, src, t, visited));

    public static int spreadInfection(ArrayList<Edge>[] graph, int src, int t, boolean[] visited) {
        ArrayDeque<Pair> que = new ArrayDeque<>();
        que.add(new Pair(src, 0));
        
        int count = 0;
        
        while(que.size() > 0) {
            Pair p = que.removeFirst();
            
            if(p.time > t)
                return count;
            
            if(visited[p.vertex] == false && p.time < t) {
                visited[p.vertex] = true;
                count++;
            }
            
            for(Edge e : graph[p.vertex]) {
                if(visited[e.nbr] == false) 
                    que.add(new Pair(e.nbr, p.time + 1));
            }
        }
        
        return count;
    }