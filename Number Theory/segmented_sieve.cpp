/*
	AUTHOR:			ADVAY AGGARWAL
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

//Using Map

map<int, bool>is_prime;

void segmented_sieve_with_map(ll l, ll r) //Time complexity - O(((r−l+1)log(r)+root(r))*log(r-l+1)) Additional log(r-l+1) due to map
{
	for (ll i = l; i <= r; i++)	is_prime[i] = true;
	for (ll i = 2; i * i <= r; i++)
	{
		for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
		{
			is_prime[j] = false;
		}
	}

	if (l == 1)	is_prime[1] = false;
}

vector<bool> segmented_sieve_without_map(ll l, ll r) // Time complexity - O((r−l+1)loglog(r)+root(r))
{
	vector<bool> is_prime(r - l + 1, true);
	for (ll i = 2; i * i <= r; i++)
	{
		for (ll j = max(i * i, ((l + i - 1) / i) * i); j <= r; j += i)
		{
			is_prime[j - l] = false;
		}
	}

	if (l == 1)	is_prime[0] = false;
	return is_prime;
}

int main()
{
	starter();
	//segmented_sieve_with_map(30, 50);
	ll l, r;
	cin >> l >> r;
	vector<bool>is_prime = segmented_sieve_without_map(l, r);
	test_cases(t)
	{
		ll n;
		cin >> n;
		cout << is_prime[n - l] << endl;
	}
	return 0;
}
