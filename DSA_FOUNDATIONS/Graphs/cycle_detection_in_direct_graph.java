import java.util.*;


public class cycle_detection_in_direct_graph {
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
        scn.close();

        System.out.println(checkCycleDirected(vtces, adj));
    }

    public static boolean checkCycleDirected(int vtces, List<List<Integer>> adj) {
        boolean[] visited = new boolean[vtces];
        boolean[] DFSVisited = new boolean[vtces];

        for(int v = 0; v < vtces; v++) {
            if(visited[v] == false) {
                boolean ans = checkCycle(adj, v, visited, DFSVisited);
                if(ans)
                    return true;
            }
        }
        return false;
    }

    private static boolean checkCycle(List<List<Integer>> adj, int src, boolean[] visited, boolean[] DFSVisited) { 
        visited[src] = true;
        DFSVisited[src] = true;

        for(int e : adj.get(src)) {
            if(visited[e] == false) {
                boolean ans = checkCycle(adj, e, visited, DFSVisited);
                if(ans)
                    return true;
            }
            else if(DFSVisited[e] == true)
                return true;
        }
        
        DFSVisited[src] = false;

        return false;
    }

    // Time complexity = O(V + E)
    // Space complexity = O(2N)
    // Auxillary(Recursive) Space = O(V) 
}
