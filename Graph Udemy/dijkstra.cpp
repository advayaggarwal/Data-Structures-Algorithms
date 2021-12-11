#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

void dijkstra(int src, int n, vector<pii>adj[], vi &distance, vi &parent)
{
	set<pii>s; //{dis, node}
	s.insert({0, src});
	distance[src] = 0;

	while (!s.empty())
	{
		auto it = s.begin();
		int currDis = it->first;
		int node = it->second;
		s.erase(it);

		for (auto p : adj[node])
		{
			int nbr = p.first;
			int w = p.second;

			if (currDis + w < distance[nbr])
			{
				s.erase({distance[nbr], nbr});

				distance[nbr] = currDis + w;
				parent[nbr] = node;
				s.insert({distance[nbr], nbr});
			}
		}
	}
}

vector<int> shortestPath(vector<vector<int>> roads, int n)
{
	vector<pii>adj[n + 2];
	vi distance(n + 2, INT_MAX);
	vi parent(n + 2, -1);

	for (int i = 0; i < roads.size(); i++)
	{
		int u = roads[i][0];
		int v = roads[i][1];
		int w = roads[i][2];

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra(1, n, adj, distance, parent);

	vector<int>res;
	int temp = n;
	while (temp != -1)
	{
		res.push_back(temp);
		temp = parent[temp];
	}

	reverse(res.begin(), res.end());
	return res;
}