#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int n, vector<vector<int>>&graph, vector<int>&path, vector<vector<int>>&ans)
{
	path.push_back(node);

	if (node == n - 1)
	{
		ans.push_back(path);
	}

	else
	{
		for (int nbr : graph[node])
		{
			dfs(nbr, n, graph, path, ans);
		}
	}

	path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph)
{
	int n = graph.size();
	vector<vector<int>>ans;
	vector<int>path;

	dfs(0, n, graph, path, ans);

	return ans;
}