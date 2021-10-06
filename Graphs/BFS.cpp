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

//Time complexity - O(V+E)
void bfs(int source, vvi &adj)
{
	int n = adj.size();
	queue<int>q;
	vector<bool>visited(n, false);

	q.push(source);
	visited[source] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		cout << node << " ";

		//Push the neighbours of current node inside q if they are not already visited and mark them visited once added into q
		for (int neigh : adj[node])
		{
			if (!visited[neigh])
			{
				q.push(neigh);
				visited[neigh] = true;
			}
		}
	}
}

int main()
{
	starter();

	int n, e; //n - #vertices, e - #edges
	cin >> n >> e;

	vvi adj(n);

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int source;
	cin >> source;

	bfs(source, adj);

	return 0;
}