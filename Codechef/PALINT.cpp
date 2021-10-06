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
		unordered_map<ll, ll>m;

		for (ll i = 0; i < n; i++)
		{
			m[a[i]]++;
		}

		ll ans = 0;
		ll operations = 1e18;

		if (x == 0)
		{
			for (auto p : m)
			{
				ans = max(ans, p.second);
			}

			cout << ans << " " << 0 << endl;
		}

		else
		{
			for (auto p : m)
			{
				ll Xor = p.first ^ x;

				auto it = m.find(Xor);

				if (it != m.end())
				{
					if ((it->second + p.second) > ans)
					{
						ans = it->second + p.second;
						operations = p.second;
					}

					else if ((it->second + p.second) == ans)
					{
						operations = min(operations, p.second);
					}
				}

				if (p.second > ans)
				{
					ans = p.second;
					operations = 0;
				}

				else if (p.second == ans)	operations = 0;
			}

			cout << ans << " " << operations << endl;
		}
	}

	return 0;
}