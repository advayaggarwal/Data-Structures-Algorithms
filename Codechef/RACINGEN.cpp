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
		ll x, r, m;
		cin >> x >> r >> m;
		r *= 60; //converting to seconds
		m *= 60;

		ll time_req = 0;
		time_req += min(x, r);
		r -= min(x, r);
		time_req += 2 * r;
		if (time_req <= m)	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}