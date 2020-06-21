/*
graph with adjacency list
problem  - mond and islands
platform - gackerearth
topic    - bfs
*/
#include<bits/stdc++.h>
using namespace std;
 
#define array2d vector<vector<int> >
#define array1d vector<int>
 
class Graph{
    private:
    int m_nodes;
    list<int> *adjList;
 
    public:
    Graph(int nodes);
    void bfs(int start);
    void addEdge(int u,int v);
};
//constructor
Graph::Graph(int nodes):m_nodes(nodes),adjList(new list<int>[nodes+2]){
}
 
//function to build graph by using adjacency list
void Graph::addEdge(int u,int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
 
//need to modify this function -> min. number of bridges required to reach from 1 to nth island
//BREADTH FIRST TRAVERSAL
void Graph::bfs(int start){
    int level = 0;
    queue<int> q;
    vector<bool> visited(m_nodes+2,false);
    q.push(start);
    visited[start] = true;
    array1d lev(m_nodes+2,0); // to keep track of level of parent. so just lev[child] = lev[parent]+1
    int neighCount = 0;
    lev[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:adjList[u]){
            if(visited[v]==false){ // this condition is to ensure that node is inserted into queue only once
                lev[v] = lev[u]+1; 
                visited[v] = true;
                q.push(v);
                if(v==m_nodes){
                    cout << lev[v] << "\n";
                    return;
                } 
            }
        }
    }
}
 
void helpMonk(int &n, int &m){
    Graph g(n);
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        g.addEdge(x,y);
    }
    g.bfs(1);
}
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m;
        cin >> n >> m;
        helpMonk(n,m);
    }
    return 0;
}

/***************
input:
2
3 2
1 2
2 3
4 5
1 2
2 3
3 4
4 2
1 3

output:
2
2
**************/