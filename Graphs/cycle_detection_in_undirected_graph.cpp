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

vi adj[100005];
bool visited[100005];
vi parent(100005);

void dfs(int source, bool &is_cycle)
{
	visited[source] = true;

	for (int nbr : adj[source])
	{
		if (!visited[nbr])
		{
			//this is a dfs tree edge
			parent[nbr] = source;
			dfs(nbr, is_cycle);
		}

		//If an adjacent vertex is visited and is not parent of current vertex, then there exists a cycle in the graph.
		else if (nbr != parent[source])
		{
			//this is a back edge, nbr---source
			//nbr is upper node
			//source is lower one
			//Print the cycle

			// int curr_node = source;
			// while (curr_node != nbr)
			// {
			// 	cout << curr_node << " ";
			// 	curr_node = parent[curr_node];
			// }
			// cout << nbr;
			is_cycle = true;
			return;
		}
	}
}

void bfs(int source, bool &is_cycle)
{
	queue<int>q;
	q.push(source);
	visited[source] = true;

	while (!q.empty())
	{
		int currnode = q.front();
		q.pop();

		for (int nbr : adj[currnode])
		{
			if (!visited[nbr])
			{
				visited[nbr] = true;
				parent[nbr] = currnode;
				q.push(nbr);
			}
			//If an adjacent vertex is visited and is not parent of current vertex,then there exists a cycle in the graph.
			else if (parent[currnode] != nbr)
			{
				is_cycle = true;
				break;
			}
		}
	}
}

bool containsCycle(int n)
{
	bool is_cycle = false;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i, is_cycle); //or bfs(0, is_cycle)
			if (is_cycle) break;
		}
	}

	return is_cycle;
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << containsCycle(n);

	return 0;
}