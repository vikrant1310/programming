#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pii>

class Graph 
{
public:
    int nodes,edges;
    vector<tuple<int,int,int> > edgeList;
    Graph(int n,int m): nodes(n),edges(m)
    {
        edgeList.reserve(nodes);
    }
    void addEdge(int u,int v,int w)
    { 
        edgeList.push_back(make_tuple(u,v,w));
    }
    vi bellmonFord(int source)
    {
        vi distance(nodes+1,INT_MAX);
        distance[source] = 0;

        //run for n-1 times to find shortest path in worst case
        for(int i=0;i<nodes-1;i++)
        {
            for(auto x : edgeList)
            {
                int from = get<0>(x);
                int to = get<1>(x);
                int w = get<2>(x);
                if(distance[from]!=INT_MAX && distance[to]>(w+distance[from]))
                    distance[to] = w+distance[from];
            }
        }

        //run once more to check for negative weight cycle
        
        for(auto x : edgeList)
        {
            int from = get<0>(x);
            int to = get<1>(x);
            int w = get<2>(x);
            if (distance[from]!=INT_MAX && distance[to] > (w + distance[from]))
            {
                cout << "NEGATIVE WEIGHT CYCLE IS THERE IN THE GRAPH\n";
                exit(0); // this is used to terminate the program with status as successful
            }
        }

        //else
        return std::move(distance);
    }
};


int main()
{
    int n,m,u,v,w;
    cin >> n >> m;
    Graph g(n,m);
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u,v,w);
    }

    vi distance = g.bellmonFord(1);

    for(int i=1;i<=n;i++)
    {
        cout << "distance from source : " << 1 << " to " << i << " is : " << distance[i] << endl;
    }    
    return 0;
}
/*
input 1:
4 4
1 2 24
1 4 20
3 1 3
4 3 -12

output :
distance from source : 1 to 1 is : 0
distance from source : 1 to 2 is : 24
distance from source : 1 to 3 is : 8
distance from source : 1 to 4 is : 20

input 2:
4 4
1 2 24
1 4 -20
3 1 3
4 3 -12

output :
NEGATIVE WEIGHT CYCLE IS THERE IN THE GRAPH
*/