#include<bits/stdc++.h>
using namespace std;

long long power(long long A, long long N)
{
	long long res = 1;

	while (N)
	{
		if (N & 1)	res = res * A % 9;

		A = A * A % 9;
		N >>= 1;
	}

	return res ? res : 9;
}

int solve(long long A, long long N)
{
	return power(A % 9, N);
}