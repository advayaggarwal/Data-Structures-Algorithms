#include <bits/stdc++.h>
using namespace std;

int bfs(int source, int n, vector<int>adj[])
{
	vector<int>visited(n + 1, false);
	vector<int>dist(n + 1, 0);
	queue<int>q;

	q.push(source);
	visited[source] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int nbr : adj[node])
		{
			if (!visited[nbr])
			{
				q.push(nbr);
				visited[nbr] = true;
				dist[nbr] = dist[node] + 1;
			}
		}
	}

	return dist[n];
}

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>>ladders)
{
	vector<int>board(n + 1, 0);

	for (auto p : snakes)
	{
		int s = p.first;
		int e = p.second;
		board[s] = e - s;
	}

	for (auto p : ladders)
	{
		int s = p.first;
		int e = p.second;
		board[s] = e - s;
	}

	vector<int>adj[n + 1];

	for (int u = 1; u <= n; u++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			int v = u + dice;
			v += board[v];

			if (v <= n)    adj[u].push_back(v);
		}
	}

	return bfs(1, n, adj);
}
