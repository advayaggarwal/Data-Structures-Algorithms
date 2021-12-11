#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int>&leader)
{
	if (leader[x] == -1)	return x;

	return leader[x] = find(leader[x], leader);
}

void Union(int x, int y, vector<int>&leader, vector<int>&rank)
{
	int l1 = find(x, leader);
	int l2 = find(y, leader);

	if (l1 != l2)
	{
		if (rank[l1] > rank[l2])	leader[l2] = l1;

		else if (rank[l1] < rank[l2])	leader[l1] = l2;

		else
		{
			leader[l1] = l2;
			rank[l2]++;
		}
	}
}

int minCostConnectPoints(vector<vector<int>> points)
{
	int n = points.size();

	vector<vector<int>>edges;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			edges.push_back({dis, i, j});
		}
	}

	sort(edges.begin(), edges.end()); //according to distances

	vector<int> leader(n, -1), rank(n, 1);
	int ans = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][1];
		int v = edges[i][2];
		int weight = edges[i][0];

		int l1 = find(u, leader);
		int l2 = find(v, leader);

		if (l1 != l2)
		{
			Union(u, v, leader, rank);
			ans += weight;
		}
	}

	return ans;
}