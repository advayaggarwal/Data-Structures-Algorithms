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

//Recursion
//Time complexity - O(s^n), n is number of denominations and s is the target amount.
int coinChange(vi &denominations, int target)
{
	if (target < 0 )	return -1;

	if (target == 0)	return 0;

	int ans = -1;
	for (int i = 0; i < denominations.size(); i++)
	{
		int coin = coinChange(denominations, target - denominations[i]);
		if (coin >= 0)	ans =  ans < 0 ? coin : min(ans, coin);
	}

	return  ans < 0 ? -1 : 1 + ans;
}

//Time complexity - O(n*target)
//Space complexity - O(target)
int coinChangeTD(vi &denominations, int target, vi &dp)
{
	if (target < 0 )	return -1;

	if (target == 0)	return 0;

	if (dp[target] != -1)	return dp[target];

	int ans = -1;
	for (int i = 0; i < denominations.size(); i++)
	{
		int coin = coinChange(denominations, target - denominations[i]);
		if (coin >= 0)	ans =  ans < 0 ? coin : min(ans, coin);
	}

	return  dp[target] = ans < 0 ? -1 : 1 + ans;
}

//Bottom Up DP
//Time complexity - O(n*target)
//Space complexity - O(target)
int coinChangeBU(vi &denominations, int target)
{
	vi dp(target + 1, INT_MAX - 1);

	dp[0] = 0;
	for (int amount = 1; amount <= target; amount++)
	{
		for (int coin : denominations)
		{
			if (amount >= coin)
			{
				dp[amount] = min(dp[amount], 1 + dp[amount - coin]);
			}
		}
	}

	return dp[target] > target ? -1 : dp[target];
}

int main()
{
	starter();

	int n, target;
	cin >> n >> target;

	vi denominations(n);
	cin >> denominations;

	vi dp(target + 1, -1);

	cout << coinChange(denominations, target) << " " << coinChangeTD(denominations, target, dp) << " " << coinChangeBU(denominations, target);

	return 0;
}