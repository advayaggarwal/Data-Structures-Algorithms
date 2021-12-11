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

const int N = 2e6 + 7;

void solve()
{
	int n;
	cin >> n;

	vi a(n);

	map<int, int>m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;

		a[i] += N;
	}

	for (auto e : m)
	{
		if (e.second >= n / 2)
		{
			cout << -1 << endl;
			return;
		}
	}


	int ans = 0;

	vi freq(N);
	vi rem(N);

	for (int i = N; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			rem[j] = a[j] % i;
			freq[rem[j]]++;
		}

		int mx = 0;
		for (int j = 0; j < n; j++)
		{
			mx = max(mx, freq[rem[j]]);
			freq[rem[j]] = 0;
		}

		if (mx >= n / 2)
		{
			ans = i;
			break;
		}
	}

	cout << (ans == N ? -1 : ans) << endl;
}

int main()
{
	starter();
	test_cases(t)
	{
		solve();
	}
	return 0;
}