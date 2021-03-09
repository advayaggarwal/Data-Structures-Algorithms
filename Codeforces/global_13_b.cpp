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

int a[107];

int main()
{
	starter();
	test_cases(t)
	{
		int n, u, v;
		cin >> n >> u >> v;
		for (int i = 1; i <= n; i++)	cin >> a[i];
		int ans = INT_MAX;
		for (int i = 2; i <= n; i++)
		{
			if (abs(a[i] - a[i - 1]) >= 2) ans = 0;
			if (abs(a[i] - a[i - 1]) == 1) ans = min(ans, min(u, v));
			if (a[i] == a[i - 1])	ans = min(ans, v + min(u, v));
		}

		cout << ans << endl;
	}
	return 0;
}