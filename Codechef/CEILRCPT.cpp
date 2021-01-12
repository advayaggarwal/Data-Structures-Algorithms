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

int count_set_bits(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)	count++;
		n = n >> 1;
	}
	return count;
}

int main()
{
	starter();
	test_cases(t)
	{
		int n;
		cin >> n;
		int rem = n % 2048;
		n /= 2048;
		cout << count_set_bits(rem) + n << endl;
	}
	return 0;
}