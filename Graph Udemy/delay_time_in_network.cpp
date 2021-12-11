#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>

void dijkstra(int src, vector<pii>adj[], vi &distance)
{
	distance[src] = 0;
	set<pii>s; //{distance, node}
	s.insert({0, src});

	while (!s.empty())
	{
		auto it = s.begin();
		int node = it->second;
		int dis_till_now = it->first;
		s.erase(it);

		for (auto n : adj[node])
		{
			int nbr = n.first;
			int w = n.second;

			if (dis_till_now + w < distance[nbr])
			{
				s.erase({distance[nbr], nbr});
				distance[nbr] = dis_till_now + w;
				s.insert({distance[nbr], nbr});
			}
		}
	}
}

int networkDelayTime(vector<vector<int>> times, int n, int k)
{
	vector<pii>adj[n + 1];
	for (int i = 0; i < times.size(); i++)
	{
		int u = times[i][0], v = times[i][1], w = times[i][2];
		adj[u].push_back({v, w});
	}

	vi distance(n + 1, INT_MAX);
	dijkstra(k, adj, distance);

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		if (distance[i] == INT_MAX)	return -1;
		ans = max(ans, distance[i]);
	}

	return ans;
}