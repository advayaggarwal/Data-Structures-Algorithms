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
There are N stones given in the form of an array, each element in array represents the height of the ith stone.
There is a frog who is initially on stone 1.

Frog will repeat the following actions some number of times to reach stone N:
	* If the frog is currently on stone i, he can jump to stone i+1 or stone i+2. Here a cost of |hi-hj| is incurred,
	  where j is the stone frog lands on.

Find the minimum possible total cost incurred before the frog reaches stone N.
*/

//Recursive
//Time complexity - O(2^n)
//Space complexity - O(n)
int minCost(vi &heights, int n, int index)
{
	if (index == n - 2)	return abs(heights[n - 2] - heights[n - 1]);
	if (index == n - 1)	return 0;

	int cost1 = abs(heights[index] - heights[index + 1]) + minCost(heights, n, index + 1);
	int cost2 = abs(heights[index] - heights[index + 2]) + minCost(heights, n, index + 2);

	return min(cost1, cost2);
}

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
int minCostTD(vi &heights, int n, int index, vi &dp)
{
	if (index == n - 2)	return abs(heights[n - 2] - heights[n - 1]);
	if (index == n - 1)	return 0;

	if (dp[index] != -1)	return dp[index];

	int cost1 = abs(heights[index] - heights[index + 1]) + minCostTD(heights, n, index + 1, dp);
	int cost2 = abs(heights[index] - heights[index + 2]) + minCostTD(heights, n, index + 2, dp);

	return dp[index] = min(cost1, cost2);
}

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
int minCostBU(vi &heights, int n)
{
	vi dp(n, 0); //dp[i] represents min cost to reach end from ith stone
	dp[n - 2] = abs(heights[n - 2] - heights[n - 1]);

	for (int i = n - 3; i >= 0; i--) //We can solve this from left to right also, but that will give min cost to reach i from start
	{
		dp[i] = min(abs(heights[i] - heights[i + 1]) + dp[i + 1], abs(heights[i] - heights[i + 2]) + dp[i + 2]);
	}

	return dp[0];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi heights(n);
	cin >> heights;

	vi dp(n, -1);
	cout << minCost(heights, n, 0) << " " << minCostTD(heights, n, 0, dp) << " " << minCostBU(heights, n);

	return 0;
}