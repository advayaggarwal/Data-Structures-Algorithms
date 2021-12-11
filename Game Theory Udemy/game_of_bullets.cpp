#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> A)
{
	int nim_sum = 0;

	for (int i = 0; i < n; i++)
	{
		nim_sum ^= A[i];
	}

	if (nim_sum == 0)	return "Isa";
	else return "Gaitonde";
}