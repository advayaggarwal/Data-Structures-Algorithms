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

//Recursive
//Time complexity - O(k^n)
//Space complexity - O(n)
int climbLaddersRecur(int n, int k)
{
	if (n < 0)	return 0;
	if (n == 0 or n == 1 )	return 1;

	int ans = 0;

	for (int i = 1; i <= k; i++)
	{
		ans += climbLaddersRecur(n - i, k); //f(n) = f(n-1) + f(n-2) + ... + f(n-k)
	}

	return ans;
}

//Top Down DP - DP with memoization
//Time complexity - O(n*k)
//Space complexity - O(n)
int climbLaddersTD(int n, int k, vi &dp)
{
	if (n < 0)	return 0;
	if (n == 0 or n == 1 )	return 1;

	if (dp[n] != -1)	return dp[n];

	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		ans += climbLaddersTD(n - i, k, dp);
	}

	return dp[n] = ans;
}

//Bottom Up DP - Iterative DP
//Time complexity - O(n*k)
//Space complexity - O(n)
int climbLaddersBU(int n, int k)
{
	vi dp(50, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k && (i - j >= 0); j++)
		{
			dp[i] += dp[i - j];
		}
	}

	return dp[n];
}

//Bottom Up DP - Iterative DP
//Time complexity - O(n+k)
//Space complexity - O(n)
int climbLaddersBUWithSlidingWindow(int n, int k)
{
	vi dp(50, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= k; i++) //Init for 1st K elements
	{
		dp[i] = 2 * dp[i - 1];
	}

	for (int i = k + 1; i <= n; i++) //Sliding window
	{
		dp[i] = (2 * dp[i - 1]) - dp[i - k - 1];
	}

	return dp[n];
}

int main()
{
	starter();

	int n, k;
	cin >> n >> k;

	vi dp(50, -1);

	cout << climbLaddersRecur(n, k) << " " << climbLaddersTD(n, k, dp) << " " << climbLaddersBU(n, k) << " " << climbLaddersBUWithSlidingWindow(n, k);

	return 0;
}