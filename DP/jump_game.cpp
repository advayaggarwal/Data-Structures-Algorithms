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
#define pii pair<int,int>


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

//Top Down DP
//Time complexity - O(n*maxJump)
int minJumpsTD(vi &jumps, int index, vi &dp)
{
	if (index == jumps.size() - 1)	return 0;
	if (index >= jumps.size())	return INT_MAX;

	if (dp[index] != -1)	return dp[index];

	int ans = INT_MAX;

	for (int jump = 1; jump <= jumps[index]; jump++)
	{
		int subprob = minJumpsTD(jumps, index + jump, dp);

		if (subprob != INT_MAX)	ans = min(ans, 1 + subprob);
	}

	return dp[index] = ans;
}

//Bottom Up DP
//Time complexity - O(n*maxJump)
int minJumpsBU(vi &jumps)
{
	int n = jumps.size();
	vi dp(n, 0); //dp[i] represents min number of jumps required from index i to reach end

	for (int i = n - 2; i >= 0; i--)
	{
		int ans = INT_MAX;

		for (int jump = 1; jump <= jumps[i]; jump++)
		{
			if (dp[i + jump] != INT_MAX) ans = min(ans, 1 + dp[i + jump]); //if I'm able to reach end from (i+jump)th index
		}

		dp[i] = ans;
	}

	return dp[0];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi jumps(n);
	cin >> jumps;

	vi dp(n, -1);

	cout << minJumpsTD(jumps, 0, dp) << " " << minJumpsBU(jumps);

	return 0;
}