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
		int n, a, b, cost = 0;
		cin >> n >> a >> b;
		char s[n + 1];
		cin.sync();
		scanf(" %s" , s);
		//printf("%s\n", s);
		int i, j;
		for (i = 0, j = n - 1; i < n && j >= 0; i++, j--)
		{
			if (i == j) break;
			if (s[j] == '1')	cost += a;
			if (s[i] == '1')	cost += b;

		}
		cost += a;
		cout << cost << endl;
	}
	return 0;
}