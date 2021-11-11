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

//Time complexity - O(n+e)
//Space complexity - O(2n + n) //2n for bool vectors and n for recursive stack
bool dfs(int source, vi adj[], vector<bool> &visited, vector<bool> &dfs_visited)
{
	visited[source] = true;
	dfs_visited[source] = true;

	for (int neigh : adj[source])
	{
		if (!visited[neigh])
		{
			if (dfs(neigh, adj, visited, dfs_visited)) return true;
		}

		else if (dfs_visited[neigh])	return true; //neigh already visited and it's also been visited in current dfs call, therefore contains a cycle
	}

	dfs_visited[source] = false;

	return false;
}

//Using BFS, Kahn's Algorithm

bool bfs(int n, vi adj[])
{
	vi indegree(n + 1, 0);

	//calculating indegrees
	for (int i = 0; i < n; i++)
	{
		for (int nbr : adj[i])
		{
			indegree[nbr]++;
		}
	}

	queue<int>q;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)	q.push(i);
	}

	int node_count = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int nbr : adj[node])
		{
			indegree[nbr]--;
			if (indegree[nbr] == 0)	q.push(nbr);
		}

		node_count++;
	}

	return node_count == n ? true : false;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vi adj[n + 5];
	vector<bool> visited(n + 5, false), dfs_visited(n + 5, false);

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	bool cycle = false;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			if (dfs(i, adj, visited, dfs_visited))
			{
				cycle = true;
				break;
			}
		}
	}

	cout << cycle;

	return 0;
}