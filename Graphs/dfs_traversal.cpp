#include<iostream>
#include<list>

using namespace std;

class Graph
{
  int V; //vertices
  list<int> *adj; //pointer to adjacency list

public:
  Graph(int V);
  void addEdge(int u, int v);
  void dfsTraversal(int n, bool visited[]);
  void dfs(int n);
};

//constructor
Graph :: Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

//to add edge to adjacency list
void Graph :: addEdge(int u, int v)
{
  adj[u].push_back(v);
}

void Graph :: dfsTraversal(int n, bool visited[])
{
  visited[n] = true;
  cout<<n<<" ";

  list<int>::iterator itr;
  for(itr=adj[n].begin(); itr!=adj[n].end(); itr++)
  {
    if(!visited[*itr])
      dfsTraversal(*itr, visited);
  }
}

//DFS traversal
void Graph :: dfs(int n)
{
  bool *visited = new bool[V];
  for(int i=0; i<V; i++)
    visited[i] = false;

  dfsTraversal(n, visited);
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(0);

    return 0;
}
