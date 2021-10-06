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
#define vvi vector<vi>

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

int combinationSum(vi &coins, int target, int i)
{
	if (target == 0)	return 1;

	if (i == coins.size() or target < 0)   return 0;

	return combinationSum(coins, target, i + 1) + combinationSum(coins, target - coins[i], i);
}

ll combinationSumTD(vi &coins, int target, int i, vvi &dp)
{
	if (target == 0)	return 1;

	if (i == coins.size() or target < 0)   return 0;

	if (dp[i][target] != -1)	return dp[i][target];

	return dp[i][target] = combinationSumTD(coins, target, i + 1, dp) + combinationSumTD(coins, target - coins[i], i, dp);
}

int combinationSumBU(vi &coins, int target)
{
	int n = coins.size();

	vvi dp(n + 1, vi(target + 1, 0));

	for (int row = 0; row <= n; row++)	dp[row][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int sum = 1; sum <= target; sum++)
		{
			int inc = 0, exc = 0;

			if (coins[i - 1] <= sum)	inc = dp[i][sum - coins[i - 1]];

			exc = dp[i - 1][sum];

			dp[i][sum] = inc + exc;
		}
	}

	return dp[n][target];
}

int main()
{
	starter();

	int n, target;
	cin >> n >> target;

	vi coins(n);
	cin >> coins;


	vvi dp(n + 1, vi(target + 1, -1));
	cout << combinationSum(coins, target, 0) << " " << combinationSumTD(coins, target, 0, dp) << " " << combinationSumBU(coins, target);

	return 0;
}