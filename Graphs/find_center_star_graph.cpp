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

int findCenter(vector<vector<int>>&edges)
{
	int n = edges.size();
	unordered_map<int, int>m;

	for (int i = 0; i < n; i++)
	{
		int u = edges[i][0], v = edges[i][1];
		m[u]++;
		m[v]++;
	}

	int total_nodes = m.size();

	for (auto p : m)
	{
		if (p.second == total_nodes - 1)	return p.first;
	}

	return -1;
}

int main()
{
	starter();

	int n;
	cin >> n;

	vvi edges(n, vi(2));

	for (int i = 0; i < n; i++)
	{
		cin >> edges[i][0] >> edges[i][1];
	}

	cout << findCenter(edges);

	return 0;
}