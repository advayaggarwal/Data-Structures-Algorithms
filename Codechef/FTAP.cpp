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
		int n;
		cin >> n;
		int ans[n + 1] = {0};
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j * i <= n; j++)
			{
				if (ans[j * i] == 0)	ans[j * i] = 1;
				else ans[j * i] = 0;
			}
		}
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i] == 1)	count++;
		}
		cout << count << endl;
	}
	return 0;
}