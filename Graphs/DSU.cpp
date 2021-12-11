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

//Cycle Detection in a undirected graph using DSU

class Graph {
	int V;
	list<pair<int, int>>l; //Edge list (u,v), means there's an edge between u and v

public:
	Graph(int V)
	{
		this->V = V;
	}

	void addEdge(int u, int v)
	{
		l.push_back({u, v});
	}

	//Find with path compression
	int findSet(int i, int parent[])
	{
		//Base case
		if (parent[i] == -1)	return i;

		return parent[i] = findSet(parent[i], parent);
	}

	//Union by rank
	void unionSet(int x, int y, int parent[], int rank[])
	{
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if (s1 != s2)
		{
			if (rank[s1] > rank[s2])
			{
				parent[s2] = s1;
			}

			else if (rank[s1] < rank[s2])
			{
				parent[s1] = s2;
			}

			else
			{
				parent[s1] = s2;
				rank[s2]++;
			}

		}
	}

	bool contains_cycle()
	{
		//DSU logic to check if graph contains cycle or not
		int *parent = new int [V + 1];
		int *rank = new int [V + 1];
		for (int i = 0; i < V; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}

		//iterate over the edge list
		for (auto it = l.begin(); it != l.end(); it++)
		{
			int u = it->first;
			int v = it->second;

			int s1 = findSet(u, parent);
			int s2 = findSet(v, parent);

			if (s1 != s2)
			{
				unionSet(s1, s2, parent, rank);
			}

			else return true;
		}

		delete [] parent;
		delete [] rank;
		return false;
	}
};

int main()
{
	starter();

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	cout << g.contains_cycle();

	return 0;
}