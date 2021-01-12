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
	int n, i, j, lead1 = 0, lead2 = 0;
	cin >> n;
	int scores[n][2];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cin >> scores[i][j];
		}
	}

	for (j = 0; j < 2; j++)
	{
		for (i = 1; i < n; i++)
		{
			scores[i][j] += scores[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		if (lead1 < (scores[i][0] - scores[i][1]))	lead1 = scores[i][0] - scores[i][1];
		else if (lead2 < (scores[i][1] - scores[i][0]))	lead2 = scores[i][1] - scores[i][0];
	}
	if (lead1 > lead2)	cout << 1 << " " << lead1;
	else cout << 2 << " " << lead2;


	return 0;
}