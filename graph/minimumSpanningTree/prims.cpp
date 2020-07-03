#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > gr[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        gr[u].push_back(make_pair(v,w));
        gr[v].push_back(make_pair(u,w));
    }

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > activeEdges;
    long long minCost = 0;
    bool visited[n+1] = {false};

    //weight,node
    activeEdges.push(make_pair(0,1));
    while(!activeEdges.empty())
    {
        pair<int,int> curr = activeEdges.top();
        activeEdges.pop();
        int weight = curr.first;
        int node = curr.second;

        //means not an active edge
        if(visited[node]) continue;

        minCost += weight;

        visited[node] = true;

        for(auto neigh : gr[node])
        {
            if(visited[neigh.first]==false)
            {
                activeEdges.push(make_pair(neigh.second,neigh.first));
            }
        }
    }
    cout << minCost << endl;
    return 0;
}
/*
input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

output:
17
*/
