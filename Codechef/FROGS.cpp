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

int W[5];
int L[5];

int main()
{
	starter();
	test_cases(t)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)	cin >> W[i];
		for (int i = 1; i <= n; i++)	cin >> L[i];
		map<int, int>m; //(W,index)
		if (n == 2)
		{
			if (W[1] == 1)	cout << 0 << endl;
			else
			{
				if (L[1] == 1)	cout << 2 << endl;
				else cout << 1 << endl;
			}
		}
		else
		{
			ll ans = 0;
			for (int i = 1; i <= n; i++)
			{
				m[W[i]] = i;
			}
			for (int i = 2; i <= n; i++)
			{
				int temp = m[i];
				int temp1 = m[i - 1];
				int x = 0; //No. of jumps required
				if (temp <= temp1)
				{
					x = ((temp1 - temp + 1) % L[temp]) == 0 ? (temp1 - temp + 1) / L[temp] : ((temp1 - temp + 1) / L[temp]) + 1;
				}
				ans += x;
				m[i] += x * L[temp]; //current index of m[i]
			}
			cout << ans << endl;
		}
	}
	return 0;
}