//Using DFS
#include<bits/stdc++.h>
using namespace std;

bool dfs(int source, vector<bool>&visited, vector<bool>&dfs_visited, vector<int>adj[])
{
	visited[source] = true;
	dfs_visited[source] = true;

	for (int nbr : adj[source])
	{
		if (!visited[nbr])
		{
			if (dfs(nbr, visited, dfs_visited, adj))	return true;
		}

		else if (dfs_visited[nbr])	return true;
	}

	dfs_visited[source] = false;

	return false;
}

bool solve(int n, vector<vector<int>>edges)
{
	vector<int>adj[n + 1];
	vector<bool>visited(n + 1, false);
	vector<bool>dfs_visited(n + 1, false);

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			if (dfs(i, visited, dfs_visited, adj))	return true;
		}
	}

	return false;
}

//Using BFS, Kahn's Algo
#include<bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<int>&indegree, vector<int> adj[])
{
	queue<int>q;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)	q.push(i);
	}

	int node_count = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int nbr : adj[node])
		{
			indegree[nbr]--;
			if (indegree[nbr] == 0)	q.push(nbr);
		}

		node_count++;
	}

	return node_count == n ? false : true;
}

bool solve(int n, vector<vector<int>>edges) {

	vector<int>adj[n + 1];
	vector<int> indegree(n + 1, 0);

	vector<bool>visited(n + 1, false);

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		indegree[v]++;
	}

	if (bfs(n, indegree, adj))   return true;
	return false;
}