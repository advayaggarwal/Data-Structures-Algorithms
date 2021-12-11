#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int findLeader(int i, vector<int>&parent)
{
	if (parent[i] == -1)	return i;

	return parent[i] = findLeader(parent[i], parent);
}

void unionSet(int x, int y, vector<int>&parent, vector<int>&rank)
{
	int l1 = findLeader(x, parent);
	int l2 = findLeader(y, parent);

	if (l1 != l2)
	{
		if (rank[l1] < rank[l2])
		{
			parent[l1] = l2;
		}

		else if (rank[l1] > rank[l2])
		{
			parent[l2] = l1;
		}

		else
		{
			parent[l2] = l1;
			rank[l1]++;
		}
	}
}

vector<int> findUselessConnection(vector<vector<int>> edges)
{
	int e = edges.size();

	vector<int>parent(N, -1);
	vector<int>rank(N, 1);

	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		int l1 = findLeader(u, parent);
		int l2 = findLeader(v, parent);

		if (l1 == l2)
		{
			return edges[i];
		}

		unionSet(u, v, parent, rank);
	}
}