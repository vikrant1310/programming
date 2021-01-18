/*
  Algorithm - KOSARAJU'S ALGO. to find strongly connected components
  1. run dfs and insert vertices in stack as per their finish time
  2. make transpose of graph
  3. pop each vertices from stack and run dfs for each unvisited vertex.
*/

#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

//design the graph(generic one)
template<typename dataType>
class Graph
{
  int V;
  unordered_map<dataType,list<dataType> > adjList;
  unordered_map<dataType,list<dataType> > revAdjList;
  
  public:
  Graph(int &&noOfVertices);
  void addEdges(dataType u, dataType v);
  int connectedComponents();
  void DFS(dataType node,unordered_map<dataType,bool> &visited, stack<dataType> &stck);
  void DFS_ForStep3(dataType node,unordered_map<dataType,bool> &visited);
};

template<typename dataType>
Graph<dataType>::Graph(int &&noOfVertices):V(noOfVertices)
{}

template<typename dataType>
void Graph<dataType>::addEdges(dataType u, dataType v)
{
  adjList[u].push_back(v);
  revAdjList[v].push_back(u);
}

template<typename dataType>
void Graph<dataType>::DFS(dataType node,unordered_map<dataType,bool> &visited, stack<dataType> &stck)
{
  visited[node] = true;

  for(auto adjNode : adjList[node])
  {
    if(visited[adjNode] == false)
      DFS(adjNode,visited,stck);
  }

  //here function call returns for respective node
  stck.push(node);
}

template<typename dataType>
void Graph<dataType>::DFS_ForStep3(dataType node,unordered_map<dataType,bool> &visited)
{
  visited[node] = true;

  for(auto adjNode : revAdjList[node])
  {
    if(visited[adjNode] == false)
      DFS_ForStep3(adjNode,visited);
  }

  cout << " " << node ;
}

template<typename dataType>
int Graph<dataType>::connectedComponents()
{
  unordered_map<dataType,bool> visited;

  //this stack stores vertices as per their finish time in dfs in first step
  stack<dataType> stck;
  for(auto p : adjList)
  {
    auto node = p.first;
    if(visited[node] == false)
      DFS(node,visited,stck);
  }

  //till here first step is completed
  //second step we already done as we store reverse of graph while filling graph

  //step3.
  visited.clear();

  int countConnectedComponents = 0;
  while(!stck.empty())
  {
    auto node = stck.top();
    stck.pop();
    if(visited[node] == false)
    {
      countConnectedComponents++;
      cout << "\ncomponenet " << countConnectedComponents << " -> " ;
      DFS_ForStep3(node,visited);
    }
  }

  return countConnectedComponents;
}

int main()
{
  Graph<string> g(6);
  g.addEdges("A","B");
  g.addEdges("A","C");
  g.addEdges("B","A");
  g.addEdges("C","B");
  g.addEdges("D","B");
  g.addEdges("D","F");
  g.addEdges("F","E");
  g.addEdges("E","D");

  int totalConnectedComponents = g.connectedComponents();

  cout << "\nconnected components are : " << totalConnectedComponents << endl;
  return 0;
}
