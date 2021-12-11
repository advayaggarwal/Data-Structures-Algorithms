#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>&visited, vector<int>adj[], vector<int>&depth)
{
	visited[node] = true;

	for (int nbr : adj[node])
	{
		if (!visited[nbr])
		{
			depth[nbr] = depth[node] + 1;
			dfs(nbr, visited, adj, depth);
		}
	}
}

string solve(int n, vector<int> stones, vector<vector<int>>edges)
{
	vector<int>adj[n + 1];

	for (int i = 0; i < n - 1; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>depth(n + 1);
	vector<bool>visited(n + 1, false);

	dfs(1, visited, adj, depth);

	for (int i = 0; i < n; i++)	stones[i] /= 2;

	vector<int>grundy(n + 1);

	for (int i = 2; i <= n; i++)
	{
		if (stones[i - 1] % 2 == 0)	grundy[i] = 0;

		else grundy[i] = depth[i];
	}

	int ans = 0;
	for (int i = 2; i <= n; i++)	ans ^= grundy[i];

	if (!ans)	return "Ross";

	return "Rachel";
}