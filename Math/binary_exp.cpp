/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//for getting input from input1.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output.txt", "w", stdout);
#endif
}

ll int exp(ll int a, ll int b)
{
	ll int result = 1;
	while (b)
	{
		if (b % 2) result = ((result % mod) * (a % mod)) % mod;
		a = ((a % mod) * (a % mod)) % mod;
		b /= 2;
	}
	return result;
}

int main()
{
	starter();
	test_cases(t)
	{
		ll int a, b;
		cin >> a >> b;
		cout << exp(a, b) << endl;
	}
	return 0;
}