#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>&graph, vector<int>&visited, int parent, int color)
{
	visited[node] = color;

	for (int nbr : graph[node])
	{
		//Not visited
		if (visited[nbr] == 0)
		{
			bool subprob = dfs(nbr, graph, visited, node, 3 - color);

			if (!subprob)	return false;
		}

		else if (nbr != parent && color == visited[nbr])	return false;
	}

	return true;
}

bool isBipartite(vector<vector<int>> graph)
{
	int n = graph.size();

	vector<int>visited(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			if (!dfs(i, graph, visited, -1, 1))	return false;
		}
	}

	return true;
}