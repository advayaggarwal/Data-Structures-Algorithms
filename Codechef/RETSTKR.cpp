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
		string s;
		cin >> s;
		int n = (int)s.size();
		int upper[n];
		int u = 0, l = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				upper[i] = 1;
				u++;
			}
			else
			{
				upper[i] = 0;
				l++;
			}
		}
		if ((upper[0] == 1) && (u == 1) && (l == n - 1))	cout << "YES" << endl;
		else
		{
			int ans = 0;
			cout << "NO" << " ";
			for (int i = 1; i < n; i++)
			{
				if (upper[i] == 1)	ans++;
			}
			cout << (upper[0] == 1 ? ans : ans + 1) << endl;
		}
	}
	return 0;
}