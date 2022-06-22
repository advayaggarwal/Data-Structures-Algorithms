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
	int n;
	cin >> n;

	vi a(n);
	cin >> a;

	vi b(a);

	sort(b.begin(), b.end());

	int l = -1, r = -1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			l = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] != b[i])
		{
			r = i;
			break;
		}
	}

	if (l == -1 or r == -1)
	{
		cout << "yes" << endl;
		cout << 1 << " " << 1;
		return;
	}

	reverse(a.begin() + l, a.begin() + r + 1);

	bool ok = a == b;

	if (ok)
	{
		cout << "yes" << endl;
		cout << l + 1 << " " << r + 1;
	}

	else cout << "no";

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