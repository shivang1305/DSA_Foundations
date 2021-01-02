/*
    DSA Foundations - Graphs                                                              Date: 17-Dec-2020

Graph Introduction. Representation of graph by adjacency matrix.
*/

import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int src; // source edge
        int dstn; // destination edge
        int weight; // weight of the current edge
        
        // parameterised constructor
        Edge(int src, int dstn, int weight) {
            this.src = src;
            this.dstn = dstn;
            this.weight = weight;
        }
    } 
    
    public static void main(String[] args) throws Exception {
        int vertices = 7; // 0, 1, 2, 3, 4, 5, 6
        
        ArrayList<Edge>[] graph = new ArrayList<Edge>[7];
        for(int i = 0; i < vertices; i++) 
            graph[i] = new ArrayList<Edge>();
        
        // manually adding vertices
        graph[0].add(new Edge(0, 3, 40));
        graph[0].add(new Edge(0, 1, 10));
        
        graph[1].add(new Edge(1, 0, 10));
        graph[1].add(new Edge(1, 2, 10));
        
        graph[2].add(new Edge(2, 3, 10));
        graph[2].add(new Edge(2, 1, 10));
        
        graph[3].add(new Edge(3, 0, 40));
        graph[3].add(new Edge(3, 2, 10));
        graph[3].add(new Edge(3, 4, 2));
        
        graph[4].add(new Edge(4, 3, 2));
        graph[4].add(new Edge(4, 5, 3));
        graph[4].add(new Edge(4, 6, 3));
        
        graph[5].add(new Edge(5, 4, 3));
        graph[5].add(new Edge(5, 6, 3));
        
        graph[6].add(new Edge(6, 5, 3));
        graph[6].add(new Edge(6, 4, 8));
        
    }
}