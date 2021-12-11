//Using DFS
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool dfs(int node, vector<bool>&visited, vector<int>adj[], int parent)
{
	visited[node] = true;

	for (int nbr : adj[node])
	{
		if (!visited[nbr])
		{
			if (dfs(nbr, visited, adj, node))	return true;
		}

		else if (nbr != parent)	return true;
	}

	return false;
}

bool solve(vector<vector<int>> edges)
{
	int n = edges.size();

	vector<int>adj[N];

	for (int i = 0; i < n; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool>visited(N, false);

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			if (dfs(i, visited, adj, -1))	return false;
		}
	}

	return true;
}


//Using DSU with path compression and union by rank
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int findSet(int i, vector<int>& parent)
{
	if (parent[i] == -1)	return i;

	return parent[i] = findSet(parent[i], parent);
}

void unionSet(int x, int y, vector<int>& parent, vector<int>&rank)
{
	int l1 = findSet(x, parent);
	int l2 = findSet(y, parent);

	if (l1 != l2)
	{
		if (rank[l1] < rank[l2])
		{
			parent[l1] = l2;
		}

		else if (rank[l1] > rank[l2])
		{
			parent[l2] = l1;
		}

		else
		{
			parent[l1] = l2;
			rank[l2]++;
		}
	}
}

bool solve(vector<vector<int>> edges)
{
	int e = edges.size();

	vector<int> parent(N, -1);
	vector<int>rank(N, 1);

	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];


		int l1 = findSet(u, parent);
		int l2 = findSet(v, parent);

		if (l1 == l2)	return false;

		unionSet(u, v, parent, rank);
	}

	return true;
}