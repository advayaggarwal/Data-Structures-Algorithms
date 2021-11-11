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

vi indegree_cal(int n, vi adj[])
{
	//Iterate over all the edges to find the indegree
	vector<int>indegree(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int nbr : adj[i])
		{
			indegree[nbr]++;
		}
	}

	return indegree;
}

//Time complexity = O(V+E)
void topological_sort_BFS(int n, vi adj[]) //Kahn's Algorithm
{
	vi indegree = indegree_cal(n, adj);

	queue<int>q; //queue will always have nodes with 0 indegree
	//Initialse the queue with nodes having 0 indegree
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 0)	q.push(i);
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";

		//iterate over the nbrs of this node and reduce their indegree by 1, as their dependency(node) is completed
		for (int nbr : adj[node])
		{
			indegree[nbr]--;

			if (indegree[nbr] == 0) //no dependendies, ready to process
			{
				q.push(nbr);
			}
		}
	}
}

void dfs(int node, vector<bool>&visited, list<int>&ordering, vi adj[])
{
	visited[node] = true;

	for (int nbr : adj[node])
	{
		if (!visited[nbr])
		{
			dfs(nbr, visited, ordering, adj);
		}
	}

	//coming back from this node
	ordering.push_front(node);
}

void topological_sort_DFS(int n, vi adj[])
{
	vector<bool>visited(n, false);
	list<int>ordering;

	//Call dfs from every node if it's not visited
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])	dfs(i, visited, ordering, adj);
	}

	for (int node : ordering)	 cout << node << " ";
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vi adj[n];

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	topological_sort_BFS(n, adj);
	cout << endl;
	topological_sort_DFS(n, adj);

	return 0;
}