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

vi adj[200005];
bool visited[200005];
vi current_connected_component;

void dfs(int current_node)
{
	visited[current_node] = true;
	current_connected_component.push_back(current_node);
	for (int neigh : adj[current_node])
	{
		if (!visited[neigh])
		{
			dfs(neigh);
		}
	}
}

int main()
{
	starter();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cycles = 0;
	for (int node = 1; node <= n; node++)
	{
		if (!visited[node])
		{
			current_connected_component.clear();
			dfs(node);

			bool is_cycle = true;
			//For graph to be a cycle no of nodes = no of edges and degree of every node = 2
			for (int curr_node : current_connected_component) //loop over all nodes of a connected component
			{
				int degree = adj[curr_node].size();
				if (degree != 2)
				{
					is_cycle = false;
					break;
				}
			}

			if (is_cycle)	cycles++;
		}
	}

	cout << cycles;

	return 0;
}