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

int bfs(int source, vi adj[], int n)
{
	vector<bool> visited(n + 1, false);
	vi distance(n + 1, 0);

	queue<int>q;
	q.push(source);
	visited[source] = true;
	distance[source] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int neigh : adj[node])
		{
			if (!visited[neigh])
			{
				q.push(neigh);
				visited[neigh] = true;
				distance[neigh] = distance[node] + 1;
			}
		}
	}

	return distance[n];
}

int min_dice_throws(int n, vector<pair<int, int>> &snakes, vector<pair<int, int>> &ladders)
{
	vi board(n + 1, 0); //storing +ve(ladder) or -ve(snake) jumps for each number, so that I can directly make an edge

	for (auto p : snakes) //-ve jump
	{
		int s = p.first;
		int e = p.second;
		board[s] = e - s;
	}

	for (auto p : ladders) // +ve jump
	{
		int s = p.first;
		int e = p.second;
		board[s] = e - s;
	}

	vi adj[n + 1];

	for (int u = 1; u <= n; u++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			int v = u + dice;
			v += board[v];
			if (v <= n)	adj[u].push_back(v);
		}
	}

	return bfs(1, adj, n);
}

int main()
{
	starter();

	int n;
	cin >> n;

	int total_snakes, total_ladders;
	cin >> total_snakes >> total_ladders;

	vector<pii> snakes, ladders;

	for (int i = 0; i < total_snakes; i++)
	{
		int s, e;
		cin >> s >> e;
		snakes.push_back({s, e});
	}

	for (int i = 0; i < total_ladders; i++)
	{
		int s, e;
		cin >> s >> e;
		ladders.push_back({s, e});
	}

	cout << min_dice_throws(n, snakes, ladders);

	return 0;
}