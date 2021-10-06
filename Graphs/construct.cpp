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

class Graph {

	int V;
	list<int> *l;

public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int i, int j, bool undir = true)
	{
		l[i].push_back(j);

		if (undir)	l[j].push_back(i);
	}

	void printAdjList()
	{
		//Iterate over all the rows
		for (int i = 0; i < V; i++)
		{
			cout << i << "--> ";
			//every element of ith linked list
			for (int node : l[i])	cout << node << " ";
			cout << endl;
		}
	}

	void bfs(int source, int dest = -1)
	{
		vector<bool>visited(V + 1, false);
		queue<int>q;
		vi distance(V + 1, 0);
		vi parent(V + 1, -1);

		q.push(source);
		visited[source] = true;
		parent[source] = source;

		while (!q.empty())
		{
			//Do some work for every node
			int node = q.front();
			q.pop();
			cout << node << " ";

			//Push the neighbours of current node inside q if they are not already visited
			for (int nbr : l[node])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;
					distance[nbr] = distance[node] + 1;
				}
			}
		}
		cout << endl;
		//Print the shortest distance
		for (int i = 0; i < V; i++)
		{
			cout << "Shortest distance from " << source << " to " << i << " is " << distance[i] << endl;
		}

		//Print the shortest path from source to any destination
		if (dest != -1)
		{
			int temp = dest;
			while (temp != source)
			{
				cout << temp << " ";
				temp = parent[temp];
			}
			cout << source;
		}
	}

	void dfsHelper(int node, vector<bool>&visited)
	{
		cout << node << " ";
		visited[node] = true;

		for (int nbr : l[node])
		{
			if (!visited[nbr])
			{
				dfsHelper(nbr, visited);
			}
		}
	}

	void dfs(int source)
	{
		vector<bool>visited(V + 1, false);
		dfsHelper(source, visited);
	}

};

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	Graph g(n);

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	g.dfs(1);

	return 0;
}