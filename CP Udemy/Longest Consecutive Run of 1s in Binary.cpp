#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
	int ans = 0, count = 0;
	for (int i = 0; i < 31; i++)
	{
		int val = 1 << i;

		if (val & n)	count++;
		else	count = 0;

		ans = max(ans, count);
	}
}