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

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
	int ans = 0;
	vector<int>deg(n, 0);

	vector<vector<int>>edge(n, vector<int>(n, 0));

	for (int i = 0; i < roads.size(); i++)
	{
		int u = roads[i][0];
		int v = roads[i][1];
		deg[u]++;
		deg[v]++;
		edge[u][v] = 1;
		edge[v][u] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ans = max(ans, deg[i] + deg[j] - edge[i][j]);
		}
	}

	return ans;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vvi roads(e, vi(2));

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;

		roads[i][0] = u;
		roads[i][1] = v;
	}

	cout << maximalNetworkRank(n, roads);

	return 0;
}