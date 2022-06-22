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

const int sz = 2;

struct Mat {

	int m[sz][sz];

	Mat() {
		memset(m, 0, sizeof(m));
	}

	void identity()
	{
		for (int i = 0; i < sz; i++)	m[i][i] = 1;
	}

	Mat operator* (Mat a)
	{
		Mat res;
		for (int i = 0; i < sz; i++)
		{
			for (int j = 0; j < sz; j++)
			{
				for (int k = 0; k < sz; k++)
				{
					res.m[i][j] += m[i][k] * a.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}

		return res;
	}
};

int fib(int n)
{
	if (n == 0)	return 0;
	else if (n <= 2)	return 1;
	Mat res;
	res.identity();

	Mat a;
	a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;

	n -= 2;

	while (n)
	{
		if (n & 1)	res = res * a;

		a = a * a;
		n >>= 1;
	}

	return (res.m[0][0] + res.m[0][1]) % mod;
}

int fibSum(int n, int m)
{
	int ans = (fib(m + 2) - fib(n + 1)) % mod;
	if (ans < 0)	ans += mod;
	return ans;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	cout << fibSum(n, m) << endl;
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