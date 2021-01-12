/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
#include<cmath>
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
		int pc, pr;
		cin >> pc >> pr;
		int digits_c = (pc % 9) ? (pc / 9) + 1 : pc / 9;
		int digits_r = (pr % 9) ? (pr / 9) + 1 : pr / 9;
		if (digits_c < digits_r) cout << 0 << " " << digits_c << endl;
		else cout << 1 << " " << digits_r << endl;
	}
	return 0;
}