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

bool compare(pair<string, ll>a, pair<string, ll>b)
{
	return a.second < b.second;
}

ll badness(vector<pair<string, ll>> &teams)
{
	sort(teams.begin(), teams.end(), compare);
	ll ans = 0;
	ll last_rank = 1;
	for (auto p : teams)
	{
		if (p.second != last_rank)
		{
			ans += abs(last_rank - p.second);
		}
		last_rank++;
	}
	return ans;
}

int main()
{
	starter();
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<pair<string, ll>>teams(n);
		for (ll i = 0; i < n; i++)
		{
			string s;
			ll x;
			cin >> s >> x;
			teams[i] = {s, x};
		}

		cout << badness(teams) << endl;
	}
	return 0;
}