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
There are N stones, for each i (1 <= i <= N), the height of Stone i is h[i]. There is a frog who is initially on Stone 1.

He will repeat the following action some number of times to reach Stone N:
	If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K.
	Here, a cost of |hi−hj| is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.
*/

//Recursive
//Time complexity - O(k^n)
//Space complexity - O(n)
int minCost(vi &heights, int n, int k, int index)
{
	if (index == n - 2)	return abs(heights[n - 2] - heights[n - 1]);
	if (index == n - 1)	return 0;

	int ans = INT_MAX;

	for (int jump = 1; jump <= k and (jump + index) < n; jump++)
	{
		ans = min(ans, abs(heights[index] - heights[index + jump]) + minCost(heights, n, k, index + jump));
	}

	return ans;
}

//Top Down DP
//Time complexity - O(n*k)
//Space complexity - O(n)
int minCostTD(vi &heights, int n, int k, int index, vi &dp)
{
	if (index == n - 2)	return abs(heights[n - 2] - heights[n - 1]);
	if (index == n - 1)	return 0;

	if (dp[index] != -1)	return dp[index];

	int ans = INT_MAX;

	for (int jump = 1; jump <= k and (jump + index) < n; jump++)
	{
		ans = min(ans, abs(heights[index] - heights[index + jump]) + minCostTD(heights, n, k, index + jump, dp));
	}

	return dp[index] = ans;
}

//Bottom Up DP
//Time complexity - O(n*k)
//Space complexity - O(n)
int minCostBU(vi &heights, int n, int k)
{
	vi dp(n, 0); //dp[i] represents min cost to reach end from ith stone
	dp[n - 2] = abs(heights[n - 2] - heights[n - 1]);

	for (int i = n - 3; i >= 0; i--) //We can solve this from left to right also, but that will give min cost to reach i from start
	{
		int ans = INT_MAX;

		for (int jump = 1; jump <= k; jump++)
		{
			ans = min(ans, abs(heights[i] - heights[i + jump]) + dp[i + jump]);
		}

		dp[i] = ans;
	}

	return dp[0];
}

int main()
{
	starter();

	int n, k;
	cin >> n >> k;

	vi heights(n);
	cin >> heights;

	vi dp(n, -1);
	cout << minCost(heights, n, k, 0) << " " << minCostTD(heights, n, k, 0, dp) << " " << minCostBU(heights, n, k);

	return 0;
}