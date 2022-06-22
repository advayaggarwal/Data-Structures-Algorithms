/*
	AUTHOR:			ADVAY AGGARWAL
*/

/* Impatient with actions, patient with results. */

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define int 	long long int
#define vi vector<int>
#define vvi vector<vi>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>
#define vpi vector<pii>
#define F first
#define S second
#define pb push_back
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2>&p) {
	in >> p.first >> p.second;
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, const vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2>&p) {
	out << p.first << " " << p.second;
	return out;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve()
{
	int n, m;
	cin >> n >> m;
	int maxi = INT_MIN;

	vvi grid(n, vi(m));
	int x, y;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> grid[i - 1][j - 1];
			if (grid[i - 1][j - 1] > maxi)
			{
				maxi = grid[i - 1][j - 1];
				x = i;
				y = j;
			}
		}
	}

	cout << max(x, n - x + 1)*max(y, m - y + 1) << endl;
}

int32_t main()
{
	starter();
	clock_t z = clock();

	int t = 1;
	cin >> t;

	while (t--)	solve();

	cerr << "Run time: " << ((double)(clock() - z) / CLOCKS_PER_SEC) << " ";
	return 0;
}