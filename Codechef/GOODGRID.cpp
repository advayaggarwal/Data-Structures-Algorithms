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
		int n, x;
		cin >> n >> x;
		bool ans = false;
		for (int i = 1; i <= n; i++)
		{
			if (x % i == 0 && x / i <= n)
			{
				ans = true;
				break;
			}
		}
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}