/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		998244353
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

const int N = 2e5 + 5;
int ans[N];



int main()
{
	starter();
	int n;
	cin >> n;
	int A[n + 1];
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		sum = (sum % mod  + A[i] % mod) % mod;
	}


	int q;
	cin >> q;

	return 0;
}