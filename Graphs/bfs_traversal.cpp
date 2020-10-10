#include<iostream>
#include<list>

using namespace std;

class Graph
{
  int V;
  list<int> *adj;  //pointer to adj list

public:
  //constructor
  Graph(int V);
  //add edge
  void addEdge(int u, int v);
  //bfs traversal
  void bfs(int n);
};

Graph :: Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v)
{
  adj[u].push_back(v);
}

void Graph :: bfs(int n)
{
  bool *visited = new bool[V];
  for(int i=0; i<V; i++)
    visited[i] = false;

  list<int> queue;

  visited[n] = true;
  queue.push_back(n);

  list<int> :: iterator itr;

  while(!queue.empty())
  {
      n = queue.front();
      cout<<n<<" ";
      queue.pop_front();

      //exploring the popped node
      for(itr=adj[n].begin(); itr!=adj[n].end(); ++itr)
      {
        if(!visited[*itr])
        {
          visited[*itr] = true;
          queue.push_back(*itr);
        }
      }
  }
}

//driver code
int main() {
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Breadth First Traversal "<< "(starting from vertex 2) \n";
  g.bfs(2);

  return 0;
}
