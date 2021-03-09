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

const int N = 1e6 + 7;
vector<bool> prime(N, true);

vi primes;

void sieve()
{
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i * i < N; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j < N; j += i)	prime[j] = false;
		}
	}

	for (int i = 2; i < N; i++)	if (prime[i])	primes.push_back(i);

}

int main()
{
	starter();
	sieve();
	test_cases(t)
	{
		int l, r;
		cin >> l >> r;
		int index = upper_bound(primes.begin(), primes.end(), r) - primes.begin();
		cout << primes[index] << endl;
	}
	return 0;
}