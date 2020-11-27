/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)
ll int is_prime[100001];
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

void sieve() //Time complexity -> O(nloglogn)
{
	is_prime[0] = is_prime[1] = 0;
	is_prime[2] = 1;
	ll int i;
	//First mark all odd numbers as prime
	for (i = 3; i <= 100000; i += 2)
	{
		is_prime[i] = 1;
	}
	//Sieve
	for (i = 3; i * i <= 100000; i += 2)
	{
		if (is_prime[i] == 1)
		{
			for (ll int j = i * i; j <= 100000; j += i)
			{
				is_prime[j] = 0;
			}
		}
	}
}

int main()
{
	starter();
	sieve();
	test_cases(t)
	{
		ll int n;
		cin >> n;
		if (is_prime[n] == 1)	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
