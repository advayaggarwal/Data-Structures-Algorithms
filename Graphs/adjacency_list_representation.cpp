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
	Graph(int v)
	{
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i, int j, bool undirected = true)
	{
		l[i].push_back(j);

		if (undirected)	l[j].push_back(i);
	}

	void printAdjList()
	{
		//Iterate over all the rows
		for (int i = 0; i < V; i++)
		{
			cout << i << "--> ";

			for (auto node : l[i])	cout << node << " ";
			cout << endl;
		}
	}
};

int main()
{
	starter();

	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);

	g.printAdjList();

	return 0;
}