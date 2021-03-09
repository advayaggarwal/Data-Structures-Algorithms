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
	int n, q;
	cin >> n >> q;
	vi a(n);
	int ones = 0, zeroes = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)	ones++;
		else zeroes++;
	}
	while (q--)
	{
		int t, x;
		cin >> t >> x;
		if (t == 1)
		{
			if (a[x - 1] == 1)
			{
				ones--;
				zeroes++;
				a[x - 1] = 0;
			}
			else
			{
				ones++;
				zeroes--;
				a[x - 1] = 1;
			}
		}
		else
		{
			if (x > ones)	cout << 0 << endl;
			else cout << 1 << endl;
		}
	}
	return 0;
}