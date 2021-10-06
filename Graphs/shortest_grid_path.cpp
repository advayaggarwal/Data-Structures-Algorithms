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

class Node {
public:
	int x, y, cost;

	Node(int x, int y, int cost)
	{
		this->x = x;
		this->y = y;
		this->cost = cost;
	}
};

class Compare {
public:
	bool operator()(const Node &a, const Node &b)
	{
		return a.cost <= b.cost;
	}
};

//Dijkstra's Algorithm
int shortest_path(vvi &grid)
{
	int m = grid.size(), n = grid[0].size();

	vvi cost(m, vi(n, INT_MAX));

	cost[0][0] = grid[0][0];

	set<Node, Compare>s;
	s.insert(Node(0, 0, cost[0][0]));

	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	while (!s.empty())
	{
		auto it = s.begin();

		int costTillNow = it->cost;
		int node_i = it->x;
		int node_j = it->y;
		s.erase(it); //Pop

		//Iterate in all the 4 directions
		for (int k = 0; k < 4; k++)
		{
			int ni = node_i + dx[k];
			int nj = node_j + dy[k];
			if (ni >= 0 and nj >= 0 and ni < m and nj < n and costTillNow + grid[ni][nj] < cost[ni][nj])
			{
				//remove if old node already exists in the set
				auto f = s.find(Node(ni, nj, cost[ni][nj]));
				if (f != s.end())	s.erase(f);

				//insert the updated node with the new cost
				cost[ni][nj] = costTillNow + grid[ni][nj];
				s.insert(Node(ni, nj, cost[ni][nj]));
			}
		}
	}

	return cost[m - 1][n - 1];
}

int main()
{
	starter();

	int m, n;
	cin >> m >> n;

	vvi grid(m, vi(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	cout << shortest_path(grid);

	return 0;
}