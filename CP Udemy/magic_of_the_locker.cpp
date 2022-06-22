#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

ll power(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)	res = (res * a) % mod;

		a = (a * a) % mod;
		b /= 2;
	}

	return res;
}

int locker(int n)
{
	int ans = 0;

	if (n <= 2)	ans = n;

	else
	{
		int cnt = n / 3, rem = n % 3;

		if (rem == 1)
		{
			ans = (power(3, cnt - 1) * 4) % mod;
		}

		else if (rem == 2)
		{
			ans = (power(3, cnt) * 2) % mod;
		}

		else
		{
			ans = power(3, cnt);
		}
	}

	return ans;
}