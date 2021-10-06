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

int minTrioDegree(int n, vector<vector<int>> &edges)
{
	vector<int>deg(n + 1, 0);
	vector<vector<int>>adjMatrix(n + 1, vector<int>(n + 1, 0));

	int ans = INT_MAX;

	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		deg[u]++;
		deg[v]++;

		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if (adjMatrix[i][j] == 1 && adjMatrix[i][k] == 1 && adjMatrix[j][k] == 1)
				{
					ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
				}
			}
		}
	}

	return ans == INT_MAX ? -1 : ans;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vvi edges(e, vi(2));
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[i][0] = u;
		edges[i][1] = v;
	}

	cout << minTrioDegree(n, edges);

	return 0;
}