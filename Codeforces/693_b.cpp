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

int main()
{
	starter();
	test_cases(t)
	{
		int n;
		cin >> n;
		int a[n];
		int sum = 0;
		int ones = 0, twoes = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
			if (a[i] == 1)	ones++;
			if (a[i] == 2)	twoes++;
		}
		if (sum & 1)	cout << "NO" << endl;
		else
		{
			if (ones == twoes)	cout << "YES" << endl;
			else if (ones > twoes) cout << "YES" << endl;
			else
			{
				twoes %= 2;
				if (twoes == 0)	cout << "YES" << endl;
				else if (twoes && ones)	cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	return 0;
}
