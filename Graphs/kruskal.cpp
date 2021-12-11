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

bool myComp(vector<int>&a, vector<int>&b)
{
	return a[2] < b[2];
}

int find(int x, vector<int>&leader)
{
	if (leader[x] == -1)	return x;

	return leader[x] = find(leader[x], leader);
}

void Union(int x, int y, vector<int>&leader, vector<int>&rank)
{
	int l1 = find(x, leader);
	int l2 = find(y, leader);

	if (l1 != l2)
	{
		if (rank[l1] < rank[l2])	leader[l1] = l2;
		else if (rank[l1] > rank[l2])	leader[l2] = l1;

		else
		{
			leader[l2] = l1;
			rank[l1]++;
		}
	}
}

int main()
{
	starter();

	int n, e;
	cin >> n >> e;

	vector<vector<int>>edges;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	sort(edges.begin(), edges.end(), myComp);

	vector<int>leader(n + 1, -1);
	vector<int>rank(n + 1, 1);
	int ans = 0;

	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0], v = edges[i][1];
		int weight = edges[i][2];

		int l1 = find(u, leader);
		int l2 = find(v, leader);

		if (l1 != l2) //not a cycle
		{
			Union(u, v, leader, rank);
			ans += weight; //add it to MST
		}
	}

	cout << ans;

	return 0;
}