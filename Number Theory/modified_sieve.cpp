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

const int N = 1e6 + 5;
static int d[N]; // d(n) is the lowest factor of n which is not 1
// therefore d[x] will always be a prime
vi primes;
vi prime_factors;
void modified_sieve() //O(N) -> amortized time complexity
{
	for (int i = 1; i < N; i++)	d[i] = i;  //setting all numbers as prime as d[x] = x iff x is prime //O(N)
	for (int i = 2; i < N; i++) //O(N)
	{
		if (d[i] == i)	primes.push_back(i);
		for (int j = 0; j < ((int)primes.size()) && primes[j] <= d[i] && i * primes[j] < N; j++) //primes.size() returns unsigned int but j is int that's why we are typecasting
		{
			d[i * primes[j]] = primes[j]; // for each x = (i*primes[j]) d[x] would be updated once
			//eg d[4 * 2] = 2, x = 8
			//therefore O(N)
		}
	}

}

void prime_factorization(int x)
{
	while (x != 1)
	{
		prime_factors.push_back(d[x]);
		x /= d[x];
	}
}

int main()
{
	starter();
	modified_sieve();
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)	cout << primes[j] << " ";
	int x;
	cin >> x;
	prime_factorization(x);
	cout << "\n";
	for (auto it : prime_factors)	cout << it << " ";
	return 0;
}