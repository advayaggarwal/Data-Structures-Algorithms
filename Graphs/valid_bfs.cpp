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

vector<int> bfs(int source, int n, vector<int>adj[])
{
	vector<bool>visited(n + 1, false);
	queue<int>q;

	q.push(source);
	visited[source] = true;

	vector<int>BFS;
	while (!q.empty())
	{
		int par = q.front();
		q.pop();
		BFS.push_back(par);

		for (int nbr : adj[par])
		{
			if (!visited[nbr])
			{
				q.push(nbr);
				visited[nbr] = true;
			}
		}
	}

	return BFS;
}

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
	vector<int>adj[n + 1];

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, int>m;
	for (int i = 0; i < n; i++)	m[sequence[i]] = i;

	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end(), [&](int u, int v) {
			return m[u] < m[v];
		});
	}

	vector<int> BFS = bfs(1, n, adj);

	return BFS == sequence;

}

int main()
{
	starter();

	int n;
	cin >> n;

	vvi edges(n - 1, vi(2));

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		edges[i][0] = u;
		edges[i][1] = v;
	}

	vi sequence(n);
	for (int i = 0; i < n; i++)	cin >> sequence[i];

	if (validBfs(n, sequence, edges)) cout << "Yes";

	else cout << "No";

	return 0;
}