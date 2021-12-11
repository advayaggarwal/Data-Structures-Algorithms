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

int main()
{
	starter();

	int n, m;
	cin >> n >> m;

	vector<int>adj[n + 1];
	vector<int>indegree(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	//Kahn's Algo
	queue<int>q;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)	q.push(i);
	}

	vector<int>dp(n + 1, 0);
	dp[1] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int nbr : adj[node])
		{
			indegree[nbr]--;
			if (indegree[nbr] == 0)	q.push(nbr);

			dp[nbr] = (dp[nbr] + dp[node]) % mod;
		}
	}

	cout << dp[n];

	return 0;
}