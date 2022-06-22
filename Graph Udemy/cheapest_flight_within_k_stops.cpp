#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k)
{
	vector<int>dist(n, INT_MAX);
	dist[src] = 0;
	for (int i = 0; i <= k; i++)
	{
		vector<int>temp(dist);
		for (vector<int>flight : flights)
		{
			if (dist[flight[0]] != INT_MAX && temp[flight[1]] > flight[2] + dist[flight[0]])
				temp[flight[1]] = flight[2] + dist[flight[0]];
		}

		dist = temp;
	}

	return dist[dst] == INT_MAX ? -1 : dist[dst];
}