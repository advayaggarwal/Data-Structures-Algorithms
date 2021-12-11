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

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
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

int dx[4] = { -2, -2, 1, -1};
int dy[4] = {1, -1, -2, -2};

map<pair<int, int>, int>m;

int grundy(int x, int y)
{
	if (m.count({x, y}))	return m[ {x, y}];
	set<int>s;
	for (int k = 0; k < 4; k++)
	{
		int i = x + dx[k];
		int j = y + dy[k];

		if (i >= 1 && i <= 15 && j >= 1 && j <= 15)
		{
			s.insert(grundy(i, j));
		}
	}

	int mex = 0;
	while (s.find(mex) != s.end())	mex++;

	return m[ {x, y}] = mex;
}

void solve()
{
	int k;
	cin >> k;

	int nimsum = 0;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;

		nimsum ^= grundy(x, y);
	}

	if (nimsum)	cout << "First" << endl;
	else cout << "Second" << endl;
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