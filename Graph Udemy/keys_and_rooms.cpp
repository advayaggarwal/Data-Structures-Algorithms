#include<bits/stdc++.h>
using namespace std;

void dfs(int source, vector<bool>&visited, vector<vector<int>>&rooms)
{
	visited[source] = true;

	for (int nbr : rooms[source])
	{
		if (!visited[nbr])
		{
			dfs(nbr, visited, rooms);
		}
	}
}

bool canVisitAllRooms(vector<vector<int>> rooms)
{
	int n = rooms.size();

	vector<bool>visited(n + 1, false);
	dfs(0, visited, rooms);

	for (int i = 1; i < n; i++)
	{
		if (!visited[i])	return false;
	}

	return true;
}