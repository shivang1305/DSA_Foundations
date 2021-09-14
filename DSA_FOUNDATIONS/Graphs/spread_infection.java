/*
    DSA Foundations - Graphs                                                              Date: 23-Dec-2020

1. You are given a graph, representing people and their connectivity.
2. You are also given a src person (who got infected) and time t.
3. You are required to find how many people will get infected in time t, if the infection spreads to neighbors of infected person in 1 unit of time.
*/      

import java.util.*;

public class spread_infection {
    static class Pair {
        int time;
        int vertex;

        Pair(int time, int vertex) {
            this.time = time;
            this.vertex = vertex;
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int vtces = scn.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        
        for (int i = 0; i < vtces; i++) 
            adj.add(new ArrayList<>());
        

        int edges = scn.nextInt();
        for (int i = 0; i < edges; i++) {
            String word = scn.next();
            String[] parts = word.split(" ");
            int u = Integer.parseInt(parts[0]);
            int v = Integer.parseInt(parts[1]);
            
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        int t = scn.nextInt();
        int src = scn.nextInt();
        scn.close();

        boolean[] visited = new boolean[vtces];

        System.out.println(spreadInfection(adj, src, t, visited));
    }

    // BFS 
    public static int spreadInfection(List<List<Integer>> adj, int src, int t, boolean[] visited) {
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
            
            for(int e : adj.get(p.vertex)) {
                if(visited[e] == false) 
                    que.add(new Pair(e, p.time + 1));
            }
        }
        
        return count;
    }

    // Time complexity = O(V + E)
    // Space complexity = O(V)
}
    
    
    