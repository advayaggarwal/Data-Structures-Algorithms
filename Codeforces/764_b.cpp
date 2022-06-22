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
	int a, b, c;
	cin >> a >> b >> c;

	if (b - a == c - b)	cout << "YES" << endl; //already an AP
	else
	{
		int d, na, nb, nc;
		//try to change a
		d = c - b;
		na = b - d;
		if ((na % a == 0) && (na > 0))
		{
			if (b - na == c - b)
			{
				cout << "YES" << endl;
				return;
			}
		}

		//try to change b
		d = (c - a) / 2;
		nb = a + d;
		if ((nb % b == 0) && (nb > 0))
		{
			if (nb - a == c - nb)
			{
				cout << "YES" << endl;
				return;
			}
		}

		//try to change c
		d = b - a;
		nc = b + d;
		if ((nc % c == 0) && (nc > 0))
		{
			if (nc - b == b - a)
			{
				cout << "YES" << endl;
				return;
			}
		}

		cout << "NO" << endl;
	}
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