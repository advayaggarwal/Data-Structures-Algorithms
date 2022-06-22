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

void solve()
{
	int n, m;
	cin >> n >> m;

	int r = n - m + 1;
	int mxi = (r * (r - 1)) / 2;
	int mni;

	int cnt = n / m;
	if (n % m == 0)
	{
		mni = m * (cnt * (cnt - 1)) / 2;
	}

	else
	{
		int cntmax = n % m;
		int cntmin = m - cntmax;

		int val1 = cntmin * (cnt * (cnt - 1)) / 2;
		int val2 = cntmax * (cnt * (cnt + 1)) / 2;

		mni = val1 + val2;
	}

	cout << mni << " " << mxi;
}

int32_t main()
{
	starter();
	clock_t z = clock();

	int t = 1;
	// cin >> t;

	while (t--)	solve();

	cerr << "Run time: " << ((double)(clock() - z) / CLOCKS_PER_SEC) << " ";
	return 0;
}