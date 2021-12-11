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

void dfs(int node, vector<bool>&visited, vector<int>adj[], vector<int>&depth)
{
	visited[node] = true;

	for (int nbr : adj[node])
	{
		if (!visited[nbr])
		{
			depth[nbr] = depth[node] + 1;
			dfs(nbr, visited, adj, depth);
		}
	}
}

string solve(int n, vi &stones, vvi &edges)
{
	vector<int>adj[n + 1];

	for (int i = 0; i < n - 1; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>depth(n + 1);
	vector<bool>visited(n + 1, false);

	dfs(1, visited, adj, depth);

	for (int i = 1; i <= n; i++)	stones[i] /= 2;

	vector<int>grundy(n + 1);

	for (int i = 2; i <= n; i++)
	{
		if (stones[i - 1] % 2 == 0)	grundy[i] = 0;

		else grundy[i] = depth[i];
	}

	int ans = 0;
	for (int i = 2; i <= n; i++)	ans ^= grundy[i];

	if (!ans)	return "Ross";

	return "Rachel";
}

int main()
{
	starter();

	int n;
	cin >> n;
	vi stones(n + 1);

	for (int i = 1; i <= n; i++) cin >> stones[i];

	vvi edges;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		edges.push_back({x, y});
	}

	cout << solve(n, stones, edges);

	return 0;
}