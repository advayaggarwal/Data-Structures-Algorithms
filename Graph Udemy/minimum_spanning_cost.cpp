#include<bits/stdc++.h>
using namespace std;

bool myComp(vector<int>&a, vector<int>&b)
{
	return a[2] < b[2];
}

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
			leader[l2] = l1;
			rank[l1]++;
		}
	}
}

int MST(int n, vector<vector<int>> edges)
{
	int e = edges.size();
	sort(edges.begin(), edges.end(), myComp);

	vector<int>leader(n + 1, -1);
	vector<int>rank(n + 1, 1);

	int ans = 0;

	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0], v = edges[i][1];
		int weight = edges[i][2];

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