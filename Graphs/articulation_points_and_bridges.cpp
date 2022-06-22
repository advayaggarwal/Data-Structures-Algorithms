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

//Tarjan's Algorithm
//Time complexity - O(V+E)
//Space complexity - O(V)
void dfs(int src, vector<int>adj[], vector<int>&par, vector<int>&disc, vector<int>&low, vector<bool>articulation_point, int &time)
{
	disc[src] = low[src] = time;
	time++;
	int count = 0; //total dfs calls from src

	for (int &nbr : adj[src])
	{
		if (disc[nbr] == -1) //nbr not visited
		{
			par[nbr] = src;
			count++;
			dfs(nbr, adj, par, disc, low, articulation_point, time);
			low[src] = min(low[src], low[nbr]);

			if (par[src] == -1) //actual source, so have to check separately
			{
				//if total dfs calls from actual source is 1 it means all other nodes are connected via edges
				//and will be visited by subsequent dfs calls
				//so actual src can't be an articulation point
				if (count >= 2)	articulation_point[src] = true;
			}
			//for bridge the condition would be low[nbr] > disc[src]
			else if (low[nbr] >= disc[src])	articulation_point[src] = true; //can't do articulation points++
		}

		else if (nbr != par[src]) //nbr visited but it's not the parent of src, it means cycle exists
		{
			low[src] = min(low[src], disc[nbr]);
		}
	}
}


int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vector<int>adj[n];

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>par(n, -1), disc(n, -1), low(n, -1);
	vector<bool>articulation_point(n, false);
	int time = 0;

	dfs(0, adj, par, disc, low, articulation_point, time);

	int totalArticulationPoints = 0;
	for (int i = 0; i < n; i++)
	{
		if (articulation_point[i])	totalArticulationPoints++;
	}

	cout << totalArticulationPoints;
	return 0;
}