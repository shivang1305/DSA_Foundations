import java.io.*;
import java.util.*;

public class components_of_graph {
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

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
      for (int i = 0; i < vtces; i++) {
         graph.add(new ArrayList<>());
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph.get(v1).add(new Edge(v1, v2, wt));
         graph.get(v2).add(new Edge(v2, v1, wt));
      }

      ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
      
      boolean[] visited = new boolean[vtces];
      
      for(int v = 0; v < vtces; v++) {
          if(visited[v] == false) {
              ArrayList<Integer> component = new ArrayList<>();
              DFS(graph, v, component, visited);
              comps.add(component);
          }
      }

      System.out.println(comps);
   }
   
   public static void DFS(ArrayList<ArrayList<Edge>> graph, int src, ArrayList<Integer> component, boolean[] visited) {
       visited[src] = true;
       component.add(src);
       
       for(Edge e : graph.get(src)) {
           if(visited[e.nbr] == false)
            DFS(graph, e.nbr, component, visited);
       }
   }
}