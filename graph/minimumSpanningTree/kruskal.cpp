#include<bits/stdc++.h>
using namespace std;

//0 indexed based data structure
class DSU
{
    public:
    vector<pair<int,pair<int,int> > > gr;
    vector<int> parent;
    int numberOfEdges;
    int minCost;
    DSU(int n,int e)
    {
        parent.resize(n);
        numberOfEdges = e;
        minCost = 0;
        gr.resize(e);
        //iota(parent.begin(),parent.end(),i); same as below loop
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int getSuperParent(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = getSuperParent(parent[x]);
    }

    void mergeSet(int w,int x,int y)
    {
        int superParentOf_x = getSuperParent(y);
        int superParentOf_y = getSuperParent(x);

        if(superParentOf_x != superParentOf_y)
        {
            minCost += w;
            parent[superParentOf_x] = superParentOf_y;
        }
    }
};

void kruskal(DSU &dsu)
{
    for(auto p1 : dsu.gr)
    {
        int weight = p1.first;
        int u = p1.second.first;
        int v = p1.second.second;
        dsu.mergeSet(weight,u,v);
    }
}

int main(int argc, char const *argv[])
{
    int edges,nodes;
    cin >> nodes >> edges;
    DSU dsu(nodes,edges);
    for(int i=0; i<edges; i++)
    {
        int w,u,v;
        cin >> u >> v >> w;
        dsu.gr[i] = make_pair(w,make_pair(u,v));
    }
    sort(dsu.gr.begin(),dsu.gr.end());
    kruskal(dsu);
    cout << "minimum cost : " << dsu.minCost << "\n";
    return 0;
}
