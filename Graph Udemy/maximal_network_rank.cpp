#include <bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads)
{
	int ans = 0;
	vector<int>deg(n, 0);

	vector<vector<int>> edge(n, vector<int>(n, 0));

	for (int i = 0; i < roads.size(); i++)
	{
		int u = roads[i][0];
		int v = roads[i][1];
		deg[u]++;
		deg[v]++;
		edge[u][v] = 1;
		edge[v][u] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ans = max(ans, deg[i] + deg[j] - edge[i][j]);
		}
	}

	return ans;
}