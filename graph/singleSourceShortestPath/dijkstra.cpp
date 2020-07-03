#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define INF 1e9

class Graph
{
    public:
    vector<pii> *gr;
    vector<int> dis;
    int nodes,edges;

    Graph(int n,int m) : nodes(n),edges(m)
    {
        gr = new vector<pii>[nodes+1];
        dis.resize(nodes+1,INF);
    }
    void addEdge(int u,int v,int w,bool bidir=true)
    {
        gr[u].push_back({v,w});
        if(bidir)
            gr[v].push_back({u,w});
    }
    void dijkstra(int source)
    {
        bool visited[nodes+1] = {false};
        dis[source] = 0;
        priority_queue<pii,vector<pii>,greater<pii> > q;

        q.push({0,source});

        while(!q.empty())
        {
            int cur = q.top().second;
            int weight = q.top().first;

            q.pop();

            if(visited[cur]) continue;
            visited[cur] = true;

            for(auto child : gr[cur])
            {
                int v = child.first;
                int w = child.second;

                if(dis[v] > (w+dis[cur]))
                {
                    dis[v] = (w+dis[cur]);
                    q.push({dis[v],v});
                }
            }
        }

        for(int i=1;i<=nodes;i++)
        {
            cout << i << " : " << dis[i] << "\n";
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,source;
        cin >> n >> m;
        Graph g(n,m);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            g.addEdge(u,v,w);            
        }
        cin >> source;
        g.dijkstra(source);
    }
    return 0;
}

/*
input : 
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

output : 
1 : 0
2 : 24
3 : 3
4 : 15
*/
