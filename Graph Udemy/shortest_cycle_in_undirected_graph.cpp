#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> edges)
{
	vector<int>adj[n + 1];
	for (int i = 0; i < (int)edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++)
	{
		vector<int>dis(n + 1, (int)1e9);
		vector<int>parent(n + 1, -1);

		queue<int>q;
		q.push(i);
		dis[i] = 0;

		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			for (int nbr : adj[node])
			{
				if (dis[nbr] == 1e9)
				{
					dis[nbr] = dis[node] + 1;
					parent[nbr] = node;
					q.push(nbr);
				}

				else if (nbr != parent[node])
				{
					ans = min(ans, dis[node] + dis[nbr] + 1);
				}
			}
		}

	}

	if (ans == INT_MAX)	return -1;
	return ans;
}