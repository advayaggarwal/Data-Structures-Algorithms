#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int source, int n, vector<int>adj[])
{
	vector<bool>visited(n + 1, false);
	queue<int>q;

	q.push(source);
	visited[source] = true;

	vector<int>BFS;
	while (!q.empty())
	{
		int par = q.front();
		q.pop();
		BFS.push_back(par);

		for (int nbr : adj[par])
		{
			if (!visited[nbr])
			{
				q.push(nbr);
				visited[nbr] = true;
			}
		}
	}

	return BFS;
}

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
	vector<int>adj[n + 1];

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, int>m;
	for (int i = 0; i < n; i++)	m[sequence[i]] = i;

	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end(), [&](int u, int v) {
			return m[u] < m[v];
		});
	}

	vector<int> BFS = bfs(1, n, adj);

	return BFS == sequence;

}