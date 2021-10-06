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

void dfs(int node, vvi &adj, vector<bool>&visited, ll &size)
{
	visited[node] = true;
	size++;

	for (auto nbr : adj[node])
	{
		if (!visited[nbr])
		{
			dfs(nbr, adj, visited, size);
		}
	}
}

ll count_pairs(int N, vector<pii> &astronauts)
{
	vvi adj(N);
	vector<bool>visited(N, false);

	for (auto p : astronauts)
	{
		adj[p.first].push_back(p.second);
		adj[p.second].push_back(p.first);
	}

	vector<ll> connected_components;

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			ll size = 0;
			dfs(i, adj, visited, size);
			connected_components.push_back(size);
		}
	}

	ll res = 0, sum = 0;
	ll n = connected_components.size();
	ll sq = 0;
	for (ll i = 0; i < n; i++)
	{
		sum += connected_components[i];
		sq += connected_components[i] * 1LL * connected_components[i];
	}

	//(a+b+c)^2 = a^2 + b^2 + c^2 + 2*(a*b + b*c + c*a)
	//res = a*b + b*c + c*a
	res = ((sum * 1LL * sum) - sq) / 2;
	return res;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vector<pii>astronauts(e);
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		astronauts[i] = {u, v};
	}

	cout << count_pairs(n, astronauts);

	return 0;
}