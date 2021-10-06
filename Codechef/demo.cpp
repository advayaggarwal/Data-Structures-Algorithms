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

int main()
{
	starter();
	test_cases(t)
	{
		ll n, x;
		cin >> n >> x;

		vector<ll> a(n);
		cin >> a;
		unordered_map<ll, ll>count;

		ll max_count = 0;
		for (ll i = 0; i < n; i++)
		{
			count[a[i]]++;
		}

		for (auto p : count)
		{
			max_count = max(max_count, p.second);
		}

		if (x == 0 or max_count == n)
		{
			cout << max_count << " " << 0 << endl;
		}

		else
		{
			ll ans = 0;
			ll operations = 0;

			for (auto iterator = count.begin(); iterator != count.end(); iterator++)
			{
				ll num = iterator->first;
				auto it = count.find(num ^ x);

				if (it != count.end() and it != iterator)
				{
					ans += (iterator->second + count[num ^ x]);
					operations += min(iterator->second, count[num ^ x]);
				}
			}

			cout << max(ans / 2, max_count) << " " << operations / 2 << endl;
		}
	}

	return 0;
}