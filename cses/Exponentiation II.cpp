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
// #ifndef ONLINE_JUDGE
// 	//for getting input from input1.txt
// 	freopen("input.txt", "r", stdin);
// 	//for writing output to output1.txt
// 	freopen("output.txt", "w", stdout);
// #endif
}

ll int exp(ll int a, ll int b, ll int m)
{
	ll int result = 1;
	while (b)
	{
		if (b % 2) result = ((result % m) * (a % m)) % m;
		a = ((a % m) * (a % m)) % m;
		b /= 2;
	}
	return result;
}

int main()
{
	starter();
	test_cases(t)
	{
		ll int a, b, c;
		cin >> a >> b >> c;
		cout << exp(a, exp(b, c, mod - 1), mod) << endl;
	}
	return 0;
}