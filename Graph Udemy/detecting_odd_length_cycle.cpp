#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>&visited, vector<vector<int>>&graph, int parent, int color)
{
	visited[node] = color;

	for (int nbr : graph[node])
	{
		if (visited[nbr] == 0)
		{
			bool subprob = dfs(nbr, visited, graph, node, 3 - color);
			if (!subprob)	return false;
		}

		else if (nbr != parent and color == visited[nbr])	return false;
	}

	return true;
}

//if bipartite, graph will not have an odd length cycle
bool solve(vector<vector<int>> graph)
{
	int n = graph.size();

	vector<int>visited(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			if (!dfs(i, visited, graph, -1, 1))	return true;
		}
	}

	return false;
}