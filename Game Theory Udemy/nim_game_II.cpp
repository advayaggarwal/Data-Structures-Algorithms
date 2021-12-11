#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> heaps)
{
	int Xor = 0;

	for (int i = 0; i < n; i++)
	{
		heaps[i] %= 4;

		Xor ^= heaps[i];
	}

	if (Xor != 0)	return "first";

	else return "second";
}