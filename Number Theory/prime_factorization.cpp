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
vi prime(N, 1);

void sieve()
{
	for (int i = 0; i < N; i++)	prime[i] = i;
	for (int i = 2; i * i < N; i++)
	{
		if (prime[i] == i)
		{
			for (int j = i * i; j < N; j += i)
			{
				if (prime[j] == j) prime[j] = i;
			}
		}
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

//Time complexity - O(Nlog(logN)) + O(T*logN)
//						sieve        queries

int main()
{
	starter();
	sieve(); //O(Nlog(logN))
	test_cases(t)
	{
		int n;
		cin >> n;
		while (n > 1) //O(logn)
		{
			cout << prime[n] << " ";
			n /= prime[n];
		}
		cout << endl;
	}
	return 0;
}