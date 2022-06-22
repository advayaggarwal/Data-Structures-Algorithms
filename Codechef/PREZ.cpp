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

bool isPossible(int mid, string &s, int &k)
{
	int req = 0;

	for (int i = mid; i >= 0; i--)
	{
		int digit = ((s[i] - '0') + req) % 10;
		if (digit != 0)	req += (10 - digit);
	}

	return k >= req;
}

void solve()
{
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int lo = 0, hi = n - 1;
	int ans = 0;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;

		if (isPossible(mid, s, k))
		{
			ans = mid + 1;
			lo = mid + 1;
		}

		else hi = mid - 1;
	}

	cout << ans << endl;
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