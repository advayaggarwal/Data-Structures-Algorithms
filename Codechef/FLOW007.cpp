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
		int n, reverse_n = 0;
		cin >> n;
		int rem;
		while (n)
		{
			rem = n % 10;
			reverse_n = reverse_n * 10 + rem;
			n /= 10;
		}
		cout << reverse_n << endl;
	}
	return 0;
}