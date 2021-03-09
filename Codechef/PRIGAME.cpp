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

const int N = 1e6 + 7;
vi is_prime(N, 1);
int ans[N];

void sieve()
{
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i * i < N; i++)
	{
		if (is_prime[i] == 1)
		{
			for (int j = i * i; j < N; j += i)	is_prime[j] = 0;
		}
	}
	for (int i = 1; i < N; i++)
	{
		ans[i] = is_prime[i] + ans[i - 1];
	}
}

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
	sieve();
	test_cases(t)
	{
		int x, y;
		cin >> x >> y;
		cout << (ans[x] > y ? "Divyam" : "Chef") << endl;
	}
	return 0;
}