#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> graph[], int V)
{
    vector<int> :: iterator itr;
    for(int i=0; i<V; i++) {
        cout<<"\nAdjacency list of vertex "<<i<<": ";
        for(auto itr=graph[i].begin(); itr!=graph[i].end(); itr++) {
            cout<<"->"<<*itr;
        }
    }
}

// Driver code
int main()
{
    int V, E;
    cout<<"Enter the number of Vertices: ";
    cin>>V;
    cout<<"\nEnter the number of Edges: ";
    cin>>E;

    vector<int> Graph[V]; //array of vectors

    for(int i=0; i<E; i++) {
      int u, v;
      cout<<"\nEnter the starting and ending vertex: ";
      cin>>u>>v;
      addEdge(Graph, u, v);
    }
    printGraph(Graph, V);
    return 0;
}
