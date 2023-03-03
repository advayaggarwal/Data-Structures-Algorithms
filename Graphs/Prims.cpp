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


//Time complexity - O(E*logE)
//Space complexity - O(E)
int prim_mst(int n, vector<pair<int, int>>adj[])
{
	//Init a min heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap {weight, node}

	//visited array that denotes whether a node has been included in MST or not
	vector<bool>visited(n + 1, false);

	int ans = 0;

	pq.push({0, 0}); //temporary edge to node 0 with weight 0

	while (!pq.empty())
	{
		//pick out the edge with minimum weight
		auto best = pq.top();
		pq.pop();

		int to = best.second;
		int weight = best.first;

		if (visited[to])
		{
			//discard the edge, and continue
			continue;
		}

		//otherwise take the current edge
		ans += weight;

		visited[to] = true;

		//Add the new edges into the queue

		for (auto x : adj[to])
		{
			if (!visited[x.first])
			{
				pq.push({x.second, x.first});
			}
		}
	}

	return ans;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vector<pair<int, int>>adj[n + 1]; //{node, weight}

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	cout << prim_mst(n, adj);

	return 0;
}