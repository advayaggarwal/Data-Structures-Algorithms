#include<bits/stdc++.h>
using namespace std;

void bfs(int n, vector<int>adj[], vector<int>&indegree, int &visited_nodes, vector<int>&ans)
{
	multiset<int>q;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)	q.insert(i);
	}

	while (!q.empty())
	{
		int node = *q.begin();
		ans.push_back(node);
		q.erase(q.begin());
		visited_nodes++;

		for (int nbr : adj[node])
		{
			indegree[nbr]--;

			if (indegree[nbr] == 0)	q.insert(nbr);
		}
	}
}

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites)
{
	vector<int>adj[numCourses];
	vector<int>indegree(numCourses, 0);

	for (int i = 0; i < (int)prerequisites.size(); i++)
	{
		int u = prerequisites[i][0];
		int v = prerequisites[i][1];

		adj[v].push_back(u);
		indegree[u]++;
	}

	vector<int>ans;
	int visited_nodes = 0;


	bfs(numCourses, adj, indegree, visited_nodes, ans);

	if (visited_nodes != numCourses)	return {};

	return ans;
}