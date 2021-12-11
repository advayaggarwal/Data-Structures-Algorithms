#include<bits/stdc++.h>
using namespace std;
#define ll long long


int find(int x, vector<int>&leader)
{
	if (leader[x] == -1) return x;

	return leader[x] = find(leader[x], leader);
}

void Union(int x, int y, vector<int>&leader, vector<int>&rank)
{
	int l1 = find(x, leader);
	int l2 = find(y, leader);

	if (l1 != l2)
	{
		if (rank[l1] < rank[l2]) leader[l1] = l2;

		else if (rank[l1] > rank[l2])    leader[l2] = l1;

		else
		{
			leader[l2] = l1;
			rank[l1]++;
		}
	}
}

long long buildRoads(vector<vector<long long>>Coordinates)
{
	int n = Coordinates.size();

	vector<pair<ll, ll>>x, y; //contains x and y coordinates of each point, {coordinate, index}

	for (ll i = 0; i < n; i++)
	{
		ll p = Coordinates[i][0], q = Coordinates[i][1];

		x.push_back({p, i});
		y.push_back({q, i});
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<vector<int>>edges;

	for (int i = 1; i < n; i++)
	{
		ll p = x[i - 1].second;
		ll q = x[i].second;

		edges.push_back({x[i].first - x[i - 1].first, p, q});
	}

	for (int i = 1; i < n; i++)
	{
		ll p = y[i - 1].second;
		ll q = y[i].second;

		edges.push_back({y[i].first - y[i - 1].first, p, q});
	}

	sort(edges.begin(), edges.end());

	ll ans = 0;

	vector<int>leader(n, -1), rank(n, 1);

	for (int i = 0; i < edges.size(); i++)
	{
		ll u = edges[i][1], v = edges[i][2];

		ll weight = edges[i][0];

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