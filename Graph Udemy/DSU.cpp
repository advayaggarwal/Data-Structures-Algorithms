#include<bits/stdc++.h>
using namespace std;

int findSet(int i, vector<int> &parent)
{
	if (parent[i] == -1)	return i;

	return findSet(parent[i], parent);
}

void unionSet(int x, int y, vector<int>&parent)
{
	int l1 = findSet(x, parent);
	int l2 = findSet(y, parent);

	if (l1 != l2)
	{
		parent[l1] = l2;
	}
}

vector<bool> DSU(vector<vector<int>>query)
{
	int n = query.size();

	vector<int>parent(100005, -1);

	vector<bool>res;

	for (int i = 0; i < n; i++)
	{
		int q = query[i][0];
		int x = query[i][1];
		int y = query[i][2];

		if (q == 1)
		{
			unionSet(x, y, parent);
		}

		else
		{
			int l1 = findSet(x, parent);
			int l2 = findSet(y, parent);

			if (l1 == l2)	res.push_back(true);
			else res.push_back(false);
		}
	}

	return res;
}