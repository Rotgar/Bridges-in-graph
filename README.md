commands:

g++ -std=c++11 main.cpp -o prog
./prog < Examples/graph1.txt

Graphs are given in .txt files as in /Examples.  
First number at top is the number of vertices.  
Below are 2 numbers in one line, that represent an edge between vertices.  
Vertex indexing starts from 0 always.  

Result for graph1.txt :  

Graph:  
0 | 1 2        
1 | 0 2  
2 | 0 1 3 4  
3 | 2 4  
4 | 3 2 5  
5 | 4  
Bridges:          
0 2  
1 2  
2 3  
2 4  
3 4  
  
0 | 1 2 - what other vertices 0 is connected to with an edge  
