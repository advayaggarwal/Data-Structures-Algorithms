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

bool dfs_helper(vi adj[], int node, vi &visited, int parent, int color)
{
	visited[node] = color; // 1 or 2, both means visited

	for (int nbr : adj[node])
	{
		//if not visited
		if (visited[nbr] == 0)
		{
			// flip the color
			bool subprob = dfs_helper(adj, nbr, visited, node, 3 - color); //if node's color is 1, nbr should be 2 and if node is 2, nbr should be 1. i.e. 3-color
			if (subprob == false)	return false;
		}

		else if (nbr != parent and color == visited[nbr])	return false;
	}

	return true;
}

bool dfs(vi adj[], int n)
{
	vi visited(n, 0); // 0 - not visited, 1 - visited and color is 1, 2 - visited and color is 2

	int color = 1;
	bool ans = dfs_helper(adj, 0, visited, -1, color);

	//colors
	for (int i = 0; i < n; i++)
	{
		cout << i << " - Color " << visited[i] << endl;
	}

	return ans;
}


int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vi adj[n];

	while (e--)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//BFS or DFS, by coloring the nodes at each step (current node has color 1, nbr should have color 2)

	if (dfs(adj, n))	cout << "Yes it's bipartite";
	else cout << "No it's not bipartite";

	return 0;
}