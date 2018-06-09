#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class Graph{

  int V; // number of vertices
  list<int> *T; // list of lists to hold vertices inside
  bool *Visited; // table showing if vertex was visited
  list<string> Bridges; // table os strings where found bridges are kept
public:

  Graph(int V)
  {
     this->V = V;
     T = new list<int>[V];
  }

  ~Graph()
  {
    delete [] Visited;
    delete [] T;
  }

  void addEdge(int a, int b)
  {
    T[a].push_back(b);
    T[b].push_back(a);
  }

  void CleanTable(bool *tab)
  {
    for(int i=0; i<V; ++i)
      tab[i] = false;
  }

  void FindBridges()
  {
    Visited = new bool[V];
    CleanTable(Visited);
    int s;
    for(int i=0; i<V; ++i)
    {
	for(auto j=T[i].begin(); j!=T[i].end(); ++j)
        {
	    if(*j>i) // to not do the same twice
	    {
	       s = 0;          // chosing the vertex from which we start checking 
	       while(s == i || s == *j)
		  s++;
	       Visited[s] = true;
		  
	       for(; s<V; ++s)
	       {
		  if(s != i && s != *j && Visited[s] == true)
		  {
	 	     for(auto it=T[s].begin(); it != T[s].end(); ++it)
		     {
		   	 if(*it != i && *it != *j && !Visited[*it])
			    Visited[*it] = true;
		     } // mark vertices as visited
		  }
		} // for s
                CheckBridge(i,*j,Visited); // check for bridges, if at least 1 vertex was not visited
		CleanTable(Visited); 
            } // if(*j>i)
	}// for j
    }// for i
  }//FindBridges()

  void CheckBridge(int a, int b, bool *tab)
  {
     for(int i = 0; i<V; ++i)
     {
	if(tab[i] == false && i!=a && i!=b)
        {
	    string aa = to_string(a), bb = to_string(b);
            string name = aa+" "+bb;
            Bridges.push_back(name);     
            break;
	}
     } 
  }

  void ShowGraph()
  {
     cout<<"Graph: "<<endl;
     for(int i = 0; i<V; ++i)
     {
	cout<<i<<" | ";
	for(auto it = T[i].begin(); it!=T[i].end(); ++it)
	{
           cout<<*it<<" ";
        }
	cout<<endl;     
     }
  } 

  void ShowBridges()
  {
     if(Bridges.size() > 0)
     {	     
	cout<<"Bridges: "<<endl;
	for(auto it = Bridges.begin(); it != Bridges.end(); ++it)
	   cout<<*it<<endl;
     }
     else 
     {
	cout<<"No bridges found"<<endl;
     }  
   }
};


#endif
