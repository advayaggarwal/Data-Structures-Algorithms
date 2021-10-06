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

void bfs(int source, vvi &adj)
{
	int n = adj.size();

	vector<bool>visited(n, false);
	vi distance(n, 0); //distance from source
	queue<int>q;

	vi parent(n, -1);

	q.push(source);
	visited[source] = true;

	while (!q.empty())
	{
		int currnode = q.front();
		q.pop();

		cout << currnode << " ";

		for (int nbr : adj[currnode])
		{
			if (!visited[nbr])
			{
				parent[nbr] = currnode;
				distance[nbr] = distance[currnode] + 1;
				q.push(nbr);
				visited[nbr] = true;
			}
		}
	}

	cout << endl;
	//Printing shortest path from source to any destination
	for (int i = 0; i < n; i++)
	{
		int destination = i, temp = destination;
		cout << "Shortest path from " << source << " to " << destination << " is ";
		while (temp != -1) //as parent of source is -1
		{
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << " which is of length " << distance[destination] << endl;
	}
}

int main()
{
	starter();

	int n, e;
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