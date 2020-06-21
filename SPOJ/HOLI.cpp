/*
platform: SPOJ
hint: pigeonhole principle | count number of people crosses each edge. 
*/
#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int nodes;
	list<pair<int,int> > *adjList;
	public:
	Graph(int n);
	void addEdge(int u,int v,int cost);
	int dfsHelpher(int node,vector<bool> &visited,vector<int> &count,long long &maxDistance);
	long long dfs();
};

Graph::Graph(int n)
{
	nodes = n;
	adjList = new list<pair<int,int> >[nodes+1];
}

void Graph::addEdge(int u,int v,int cost)
{
	adjList[u].push_back(make_pair(v,cost));
	adjList[v].push_back(make_pair(u,cost));
}

int Graph::dfsHelpher(int node,vector<bool> &visited,vector<int> &count,long long &maxDistance)
{
	visited[node] = true;
	count[node] = 1;
	for(const auto &neigh : adjList[node])
	{
		int neigh_node = neigh.first;
		int edgeWeight = neigh.second;
		if(visited[neigh_node]==false)
		{
			count[node] += dfsHelpher(neigh_node,visited,count,maxDistance);
			int left = count[neigh_node];
			int right = nodes-left;
			maxDistance += 2*min(left,right)*edgeWeight;
		}
	}
	return count[node];
}

long long Graph::dfs()
{
	vector<bool> visited(nodes+1,false);
	vector<int> count(nodes+1,0);
	long long maxDistance = 0;
	dfsHelpher(1,visited,count,maxDistance);
	return maxDistance;
}
int main()
{
	int tc;
	cin >> tc;
	int i=1;
	while(i<=tc)
	{
		int n,x,y,z;
		cin >> n;
		Graph gObj(n);
		for(int i=0; i<(n-1); i++)
		{
			cin >> x >> y >> z;
			gObj.addEdge(x,y,z);
		}
		cout << "Case #" << i << ": " << gObj.dfs() << "\n";
		i++;
	}
	return 0;
}
