/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

vector<int> primes;
vector<bool> prime(1000001, true);
void sieve()
{
	int i, j;
	prime[0] = prime[1] = false;
	for (i = 2; i * i <= 1000000; i++)
	{
		if (prime[i] == true)
		{
			for (j = i * i; j <= 1000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	for (i = 2; i <= 1000000; i++)
	{
		if (prime[i] && prime[i - 2])	primes.push_back(i);
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
		int n;
		cin >> n;
		int count = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
		cout << count << endl;
	}
	return 0;
}