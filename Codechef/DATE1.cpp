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

int main()
{
	starter();
	test_cases(t)
	{
		ll a, y, x;
		cin >> a >> y >> x;
		// ll ans;
		// ll res;
		// ll low = 0, hi = a;
		// while (low <= hi)
		// {
		// 	ll mid = low + (hi - low) / 2;
		// 	if ((mid + y) > a)
		// 	{
		// 		res = mid;
		// 		hi = mid - 1;
		// 	}

		// 	else low = mid + 1;
		// }
		// //cout << res << endl;
		// ans = (a - res + 1) * 1LL * x;
		// //if (res == -1)	cout << x << endl;
		// if (y > a)	cout << a*x + 1 << endl;
		// else cout << ans << endl;

		if (y > a)	cout << a*x + 1 << endl;
		else cout << x*y << endl;
	}
	return 0;
}