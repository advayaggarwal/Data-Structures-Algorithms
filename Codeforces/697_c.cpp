/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
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

ll int nc2(ll int n)
{
	return (n * (n - 1)) / 2;
}

int main()
{
	starter();
	test_cases(t)
	{
		int a, b, k;
		cin >> a >> b >> k;
		vi boys(a, 0);
		vi girls(b, 0);
		ll count = nc2(k);
		for (int i = 0; i < k; i++)
		{
			int x;
			cin >> x;
			boys[x - 1]++;
		}
		for (int i = 0; i < k; i++)
		{
			int x;
			cin >> x;
			girls[x - 1]++;
		}
		for (int i : boys)
		{
			count -= nc2(i);
		}
		for (int i : girls)
		{
			count -= nc2(i);
		}
		cout << count << endl;
	}
	return 0;
}