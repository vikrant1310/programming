/*
all pair shortest path algorithm
T(V) = O(V^3)
S(V) = O(V^2)
*/

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define ll long long

vector<vi> floydWasrhal(int &n,vector<vpii> &adjList)
{
    vector<vi> distance(n+1,vi(n+1,1e9));
    //initialize the distance matrix
    for(int i=1;i<=n;i++)
    {
        distance[i][i] = 0;
        for(auto edges : adjList[i])
        {
            int v = edges.first;
            int w = edges.second;
            distance[i][v] = w;
        }
    }

    /*
	phases 1 to n
    here k is intermediate element/node with which we measure the distance between each pair
    some tweak can be done in case of undirected graph - use upper triangular matrix
	*/
    for(int k = 1; k <= n; k++)
    {
        //for row
        for(int r = 1; r <= n; r++)
        {
            //for column
            for(int c = 1; c <= n; c++)
            {
                if(distance[r][c] > (distance[r][k]+distance[k][c]))
                    distance[r][c] = (distance[r][k]+distance[k][c]);
            }
        }
    }
    //for negative weight cycle - if diagonal elements has -ve value then -ve weight cycle
    for(int i = 1; i <= n; i++)
    {
        if(distance[i][i]<0)
        {
            cout << "negative weight cycle present in the graph\n";
            exit(0);
        }
    }
    return std::move(distance);
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    vector<vpii> adjList(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        //taking graph as undirected one
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    vector<vi> distance = floydWasrhal(n,adjList);

    for(int r = 1; r <= n; r++)
    {
        for(int c = 1; c <= n; c++)
            cout << r << "," << c << " : " << distance[r][c] << "\n";
    }
    return 0;
}
/***********************************
input :
4 5
1 2 3
1 3 5
2 3 1
3 4 2
2 4 1

output:
1,1 : 0
1,2 : 3
1,3 : 4
1,4 : 4
2,1 : 3
2,2 : 0
2,3 : 1
2,4 : 1
3,1 : 4
3,2 : 1
3,3 : 0
3,4 : 2
4,1 : 4
4,2 : 1
4,3 : 2
4,4 : 0

***********************************/
