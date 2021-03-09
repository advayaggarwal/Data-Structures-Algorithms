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


ll ans[100005];

void solve()
{
	ans[1] = 1;
	for (int i = 2; i < 100005; i++)
	{
		ans[i] = ans[i - 1] + setbits(ans[i - 1]);
	}
}

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
	solve();
	test_cases(t)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}