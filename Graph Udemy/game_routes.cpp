#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int gameRoutes(int n, vector<vector<int>> edges)
{
	vector<int>adj[n + 1];

	vector<int>indegree(n + 1, 0);

	int e = edges.size();

	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		indegree[v]++;
	}

	//Kahn's Algo
	queue<int>q;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)	q.push(i);
	}

	vector<int>dp(n + 1, 0);
	dp[1] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int nbr : adj[node])
		{
			indegree[nbr]--;
			if (indegree[nbr] == 0)	q.push(nbr);

			dp[nbr] = (dp[nbr] + dp[node]) % mod;
		}
	}

	return dp[n];
}