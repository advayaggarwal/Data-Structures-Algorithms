/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

ll sum_digits(ll n) //O(logn)
{
	ll sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	starter();
	ll n, s;
	cin >> n >> s;
	ll l = s;
	ll r = 1e18;
	ll res = -1;
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		if (mid - sum_digits(mid) >= s)
		{
			res = mid;
			//cout << res << endl;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (res > n || res < s)	cout << 0;
	else cout << n - res + 1;
	return 0;
}