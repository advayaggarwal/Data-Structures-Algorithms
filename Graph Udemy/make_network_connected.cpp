#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int>&leader)
{
	if (leader[i] == -1)	return i;

	return leader[i] = find(leader[i], leader);
}

void unionSet(int i, int j, vector<int>&leader, vector<int>&rank)
{
	int l1 = find(i, leader);
	int l2 = find(j, leader);

	if (l1 != l2)
	{
		if (rank[l1] > rank[l2])
		{
			leader[l2] = l1;
		}

		else if (rank[l1] < rank[l2])
		{
			leader[l1] = l2;
		}

		else
		{
			leader[l1] = l2;
			rank[l2]++;
		}
	}
}

int makeConnected(int n, vector<vector<int>> connections)
{
	int e = connections.size();

	vector<int>leader(n, -1);
	vector<int>rank(n, 1);

	int extra = 0, components = 0;

	for (int i = 0; i < e; i++)
	{
		int u = connections[i][0];
		int v = connections[i][1];

		int l1 = find(u, leader);
		int l2 = find(v, leader);

		if (l1 != l2)
		{
			unionSet(u, v, leader, rank);
		}

		else
		{
			extra++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (find(i, leader) == i)
		{
			components++;
		}
	}

	return extra >= components - 1 ? components - 1 : -1;
}