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
		if (rank[l1] < rank[l2])	leader[l1] = l2;

		else if (rank[l1] > rank[l2])	leader[l2] = l1;

		else
		{
			leader[l1] = l2;
			rank[l2]++;
		}
	}
}

int specialPath(int n, vector<int> a, vector<vector<int>> edges, int start, int end)
{
	vector<int>leader(n + 1, -1), rank(n + 1, 1);
	int e = edges.size();

	int low = 0, hi = 1e6;
	int ans = INT_MAX;

	while (low <= hi)
	{
		leader = vector<int>(n + 1, -1);
		rank = vector<int>(n + 1, 1);

		int mid = low + (hi - low) / 2;

		for (int i = 0; i < e; i++)
		{
			int u = edges[i][0], v = edges[i][1];

			if (abs(a[u - 1] - a[v - 1]) <= mid)
			{
				Union(u, v, leader, rank);
			}
		}

		if (find(start, leader) == find(end, leader))
		{
			ans = mid;
			hi = mid - 1;
		}

		else	low = mid + 1;
	}

	return ans;
}