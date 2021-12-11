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

//Time complexity - O(V*E)
vector<int> bellmanFord(int n, int src, vector<vector<int>>&edges)
{
	vector<int>dist(n + 1, INT_MAX);
	dist[src] = 0;

	//relax all edges n-1 times
	for (int i = 0; i < n - 1; i++)
	{
		for (auto edge : edges)
		{
			int u = edge[0], v = edge[1], w = edge[2];
			if (dist[u] != INT_MAX and dist[u] + w < dist[v]) //Relaxation step
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	//negative weight cycle detection
	for (auto edge : edges)
	{
		int u = edge[0], v = edge[1], w = edge[2];
		if (dist[u] != INT_MAX and dist[u] + w < dist[v]) //Relaxation step
		{
			//since distance is still decreasing after n-1 relaxations, it means there is negative weight cycle
			cout << "Negative weight cycle found" << endl;
			exit(0); //No point of returning the distance vector
		}
	}

	return dist;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;
	vector<vector<int>>edges;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	vector<int>dist = bellmanFord(n, 0, edges);

	for (int i = 0; i < n; i++)
	{
		cout << "Node " << i << " is at distance " << dist[i] << endl;
	}

	return 0;
}