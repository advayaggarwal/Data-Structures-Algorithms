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

void dijkstra(int src, int n, vector<pii>adj[], vi &distance)
{
	set<pii>s; //{distance, node}, we can also use min heap

	distance[src] = 0;
	s.insert({0, src});

	while (!s.empty())
	{
		auto it = s.begin();

		int distTillNow = it->first;
		int node = it->second;

		s.erase(it); //Pop

		//Iterate over the neighbours of node

		for (auto nbrPair : adj[node])
		{
			int nbr = nbrPair.first;
			int currentEdge = nbrPair.second;

			if (distTillNow + currentEdge < distance[nbr])
			{
				//remove if nbr already exists in the set
				auto f = s.find({distance[nbr], nbr});
				if (f != s.end())	s.erase(f);

				//insert the updated value with the new distance
				distance[nbr] = distTillNow + currentEdge;
				s.insert({distance[nbr], nbr});
			}
		}
	}

	//Single source shortest distance to all other nodes
	for (int i = 0; i < n; i++)
	{
		cout << "Node " << i << " " << "Distance " << distance[i] << endl;
	}

}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vector<pii>adj[n + 5];

	vi distance(n + 5, INT_MAX); //can also be used as visited array, INT_MAX means not yet visited

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra(0, n, adj, distance);

	return 0;
}