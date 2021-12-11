#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies)
{
	int n = candies.size();
	unordered_set<int>s(candies.begin(), candies.end());

	if (s.size() <= n / 2)	return s.size();
	else return n / 2;
}