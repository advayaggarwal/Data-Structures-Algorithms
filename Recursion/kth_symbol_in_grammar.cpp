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

int solve(int n, int k)
{
	if (n == 1 && k == 1) return 0;
	int mid = (1 << n - 1) / 2; 			// mid is half of the lengh and length is 2^(n-1)
	if (k <= mid) return  solve(n - 1, k);
	else return  !(solve(n - 1, k - mid));
}

int main()
{
	starter();
	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
	return 0;
}