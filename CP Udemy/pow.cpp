#include<bits/stdc++.h>
using namespace std;

string solve(int A, int B, int C)
{
	bool pos1 = (A >= 0 || C % 2 == 0);
	bool pos2 = (B >= 0 || C % 2 == 0);

	if (pos1 && pos2)
	{
		if (abs(A) > abs(B))	return ">";
		else if (abs(A) < abs(B))	return "<";
		else return "=";
	}

	else if (!pos1 && !pos2)
	{
		if (abs(A) > abs(B))	return "<";
		else if (abs(A) < abs(B))	return ">";
		else return "=";
	}

	else if (pos1)	return ">";

	return "<";
}