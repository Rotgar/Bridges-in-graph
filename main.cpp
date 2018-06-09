#include "graph.hpp"

int main()
{
  int v, a, b;
  cin>>v;
  Graph G(v);
  
  while(cin>>a>>b)
  {
    G.addEdge(a,b);
  }
  G.ShowGraph(); 
  G.FindBridges();
  G.ShowBridges();
}


