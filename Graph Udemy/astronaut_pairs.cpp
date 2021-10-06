#include<bits/stdc++.h>
using namespace std;

int dfs(int source, vector<bool>&visited, vector<int>adj[])
{
	visited[source] = true;
	int cs = 1;

	for (int nbr : adj[source])
	{
		if (!visited[nbr])
		{
			cs += dfs(nbr, visited, adj);
		}
	}

	return cs;
}

int count_pairs(int N, vector<pair<int, int> > astronauts)
{
	vector<int>adj[N + 1];
	vector<bool>visited(N + 1, false);

	for (int i = 0; i < astronauts.size(); i++)
	{
		int u = astronauts[i].first;
		int v = astronauts[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>connected_components;

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			connected_components.push_back(dfs(i, visited, adj));
		}
	}

	int total_sum = 0, sq_sum = 0;

	for (int i = 0; i < connected_components.size(); i++)
	{
		total_sum += connected_components[i];
		sq_sum += (connected_components[i] * connected_components[i]);
	}

	return ((total_sum * total_sum) - sq_sum) / 2;

}