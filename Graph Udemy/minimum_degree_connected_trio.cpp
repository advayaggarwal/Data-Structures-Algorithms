#include<bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges)
{
	vector<int>deg(n + 1, 0);
	vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));

	int ans = INT_MAX;

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		deg[u]++;
		deg[v]++;

		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if (adjMatrix[i][j] == 1 && adjMatrix[i][k] == 1 && adjMatrix[j][k] == 1)
				{
					ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
				}
			}
		}
	}

	return ans == INT_MAX ? -1 : ans;
}