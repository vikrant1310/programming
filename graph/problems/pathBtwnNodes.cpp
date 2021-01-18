/*
problem : find path between two given nodes
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class Graph
{
    int V;
    unordered_map<int,vector<int> > adjList;
    
    public:
    Graph(int n):V(n)
    {}
    void addEdges(int u,int v)
    {
        adjList[u].push_back(v);
    }
    void findPaths(int start, int end);
    bool dfs(int source, int start, int end, int level,list<int> &path);
};

bool Graph::dfs(int source, int start, int end, int level,list<int> &path)
{
    bool isPath = false;
    if(source == end )
    {
        if(level ==1)
            cout << start << " -> " << source << endl;
        return true;
    }

    for(const auto &adjNode : adjList[source])
    {
        if(dfs(adjNode,start,end,level+1,path))
        {
            path.push_front(adjNode);
            //means we got the path and return from from all calls
            if(level==1)
            {
                cout << start << " -> " << source << " ";
                //print path and reset path vector for new path
                for(const auto &node : path)
                    cout << node << " ";
                cout << endl; 
                path.clear();
            }
            
            isPath = true;
        }
    }

    if(isPath) return true;
    else return false;
}

void Graph::findPaths(int start, int end)
{
    list<int> path;
    cout << "\nPath from " << start << " to " << end << endl ;
    for(auto adjNode : adjList[start])
    {
        dfs(adjNode,start,end,1,path);
    }
}

int main()
{
    int start,end;
    Graph g(5);
    
    g.addEdges(1,2);
    g.addEdges(2,5);
    g.addEdges(1,5);
    g.addEdges(1,3);
    g.addEdges(3,5);
    g.addEdges(2,4);
    g.addEdges(4,3);

    cout << "Enter start and end node to find Path between them : ";
    cin >> start >> end;
    
    g.findPaths(start,end);

    cout << "\nkeep Learning..........." << endl;
    return 0;
}

/*
Enter start and end node to find Path between them : 1 5

Path from 1 to 5
1 -> 2 5
1 -> 2 4 3 5
1 -> 5
1 -> 3 5

keep Learning...........
*/
