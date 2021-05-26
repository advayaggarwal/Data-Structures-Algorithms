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
		ll n;
		cin >> n;
		int x = n % 4;
		ll ans = (n / 4) * 44;
		if (n == 1)	ans = 20;
		else if (n == 2)	ans = 36;
		else if (n == 3)	ans = 51;
		else if (n == 4)	ans = 60;
		else
		{
			if (x == 0)
			{
				ans += (4 * 4);
			}
			else if (x == 1)
			{
				ans += (12 + 20);
			}
			else if (x == 2)
			{
				ans += (8 + 40 - 4);
			}
			else if (x == 3)
			{
				ans += (4 + 60 - 9);
			}
		}
		cout << ans << endl;
	}
	return 0;
}