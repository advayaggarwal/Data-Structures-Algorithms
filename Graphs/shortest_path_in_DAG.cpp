/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>
#define vvi vector<vi>

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/*
For all who are wondering the intution behind Topological sorting and why haven't we use simple DFS or BFS from
the source node instead.

lets say you want to do it using DFS
yes you can do it using DFS, but consider the case when you already updated a node's distance by a dfs() call
and lets say its 7 and as it is DFS then its obvious that you also have updated all the nodes in its segment of DFS
call. now you have reached to the same node from different dfs() call and now the distance is 4, so in order
to update all the nodes which were affected by the DFS call previously on the node considering distance as 7,
you now again have to do the same so that its updated with new min distance.
Same is the scenario for the simple BFS approach, we have to push node with the new distance again and again.

Time complexity will also increase in that case, since we are updating nodes distances and pushing
nodes in Queue again and again.

This multiple time calling DFS/BFS degrades the Time Complexity, hence Topological Ordering save you from that
overhead as you already know which nodes will come after the current node, so you keep on updating it .
*/

//Using simple BFS shortest path algorithm
void bfs(int source, int n, vector<pii>adj[])
{
	vi distance(n, INT_MAX);

	distance[source] = 0;

	queue<pii>q; //{node, distance}
	q.push({source, 0});

	while (!q.empty())
	{
		int node = q.front().first;
		int curr_distance = q.front().second;
		q.pop();

		for (auto nbr : adj[node])
		{
			int neigh = nbr.first;
			int cost = nbr.second;
			if (curr_distance + cost < distance[neigh])
			{
				distance[neigh] = curr_distance + cost;
				q.push({neigh, distance[neigh]});
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << i << " -> " << distance[i] << endl;
	}
}

//Using Topological sort
//Time complexity - O(N+E)*2
//Space complexity - O(2N)

void dfs(int node, vector<pii>adj[], vector<bool>&visited, stack<int> &topo)
{
	visited[node] = true;

	for (auto nbr : adj[node])
	{
		int neigh = nbr.first;
		if (!visited[neigh])
		{
			dfs(neigh, adj, visited, topo);
		}
	}

	topo.push(node);
}

void shortestDistanceFromSource(int source, int n, vector<pii>adj[])
{
	vector<bool>visited(n, false);
	stack<int> topo;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])	dfs(i, adj, visited, topo);
	}

	vi distance(n, INT_MAX);

	distance[source] = 0;

	while (!topo.empty())
	{
		int node = topo.top();
		topo.pop();

		//if the node has been reached previously
		if (distance[node] != INT_MAX)
		{
			for (auto neigh : adj[node])
			{
				int nbr = neigh.first;
				int weight = neigh.second;

				if (distance[node] + weight < distance[nbr])
				{
					distance[nbr] = distance[node] + weight;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << i << " -> " << distance[i] << endl;
	}
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vector<pii>adj[n + 1];

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
	}

	int source;
	cin >> source;

	bfs(source, n, adj);
	cout << endl;
	shortestDistanceFromSource(source, n, adj);

	return 0;
}