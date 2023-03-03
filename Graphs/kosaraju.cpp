/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>
#define vvi vector<vi>

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/*

Kosaraju's algorithm is used to find Number of Strongly Connected Components.
Strongly Connected Components are only valid to Directed Graphs
Strongly connected - A directed graph is strongly connected if there is a path between all pairs of vertices.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.

Algorithm -

1. Sort all the edges according to finishing time by applying DFS. The node which finishes last will appear first
2. Reverse the graph (reverse all the edges)
3. Do a DFS

*/

void dfs(int src, vector<int>adj[], vector<bool>&visited, stack<int>&st)
{
	visited[src] = true;
	for (int nbr : adj[src])
	{
		if (!visited[nbr])	dfs(nbr, adj, visited, st);
	}
	st.push(src); //node which finishes last will be at the top of the stack
}

void Dfs(int src, vector<int>adjT[], vector<bool>&visited)
{
	visited[src] = true;
	for (int nbr : adjT[src])
	{
		if (!visited[nbr])	Dfs(nbr, adjT, visited);
	}
}

//Time complexity - O(V+E) , traversing the whole graph 3 times
//Space complexity - O(V+E)
int kosaraju(int n, vector<int>adj[])
{
	vector<bool>visited(n);
	stack<int>st; //Using stack so that we can sort them according to finishing time
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])	dfs(i, adj, visited, st);
	}

	vector<int>adjT[n]; //To store the reverse graph

	for (int i = 0; i < n; i++)
	{
		visited[i] = false; //clearing so that we can use it again to apply dfs
		for (int nbr : adj[i])
		{
			adjT[nbr].push_back(i);
		}
	}


	int scc = 0; //number of strongly connected components
	while (!st.empty()) //perform dfs according to finishing time
	{
		int node = st.top();
		st.pop();

		if (!visited[node])
		{
			scc++;
			Dfs(node, adjT, visited);
		}
	}

	return scc;
}


int main()
{
	starter();
	int n, e;
	cin >> n >> e;

	vector<int>adj[n];

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	cout << kosaraju(n , adj);

	return 0;
}