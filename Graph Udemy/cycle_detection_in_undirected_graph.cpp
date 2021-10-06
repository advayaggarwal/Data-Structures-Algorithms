#include<bits/stdc++.h>
using namespace std;

bool dfs(int source, vector<bool>&visited, vector<int>adj[], int par)
{
	visited[source] = true;

	for (int nbr : adj[source])
	{
		if (!visited[nbr])
		{
			if (dfs(nbr, visited, adj, source)) return true;
		}

		else if (nbr != par)	return true;
	}

	return false;
}

bool solve(int n, vector<vector<int> > edges)
{
	vector<int>adj[n + 1];

	int e = edges.size();

	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool>visited(n + 1, false);

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			if (dfs(i, visited, adj, -1))	return true;
		}
	}

	return false;
}