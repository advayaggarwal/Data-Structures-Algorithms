#include<bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>> edges)
{
	int n = colors.size();

	vector<int>adj[n];
	vector<int>indegree(n, 0);

	for (int i = 0; i < (int)edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		indegree[v]++;
	}

	queue<int>q;
	vector<vector<int>>cnt(n, vector<int>(26, 0)); //cnt[i][j] represents max value of color j in a path ending at i

	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			cnt[i][colors[i] - 'a'] = 1;
		}
	}

	int ans = 0, nodes = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		nodes++;

		int val = *max_element(cnt[u].begin(), cnt[u].end()); //max value of any color in a path ending at u
		ans = max(ans, val);

		for (int v : adj[u])
		{
			for (int i = 0; i < 26; i++)
			{
				cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == (colors[v] - 'a')));
			}

			indegree[v]--;

			if (indegree[v] == 0)	q.push(v);
		}
	}

	return nodes == n ? ans : -1;
}