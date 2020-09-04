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
	//for getting input from input1.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output.txt", "w", stdout);
#endif
}


int main()
{
	starter();
	int n, count = 0;
	cin >> n;
	for (int i = 31; i >= 0; i--)
	{
		if (n & (1 << i))
		{
			count++;
			cout << "1";
		}
		else
		{
			if (count) cout << "0";
			else continue;
		}
	}
	return 0;
}