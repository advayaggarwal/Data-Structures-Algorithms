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


//Given a set of non-negative integers, and a value sum, determine if there is a subset
//of the given set with sum equal to given sum.

//Recursive
//Time complexity - O(2^n)
//Space complexity - O(n)
bool subsetSum(vi &arr, int target, int index)
{
	if (index == arr.size())	return false;

	if (target == 0)	return true;

	bool inc = false, exc = false;

	if (target >= arr[index]) inc = subsetSum(arr, target - arr[index], index + 1);

	exc = subsetSum(arr, target, index + 1);

	return (inc || exc);
}

//Top Down DP
//Time complexity - O(n*target)
//Space complexity - O(n*target)
bool subsetSumTD(vi &arr, int target, int index, vvi &dp)
{
	if (index == arr.size())	return false;

	if (target == 0)	return true;

	if (dp[index][target] != -1)	return dp[index][target];

	bool inc = false, exc = false;

	if (target >= arr[index])	inc = subsetSumTD(arr, target - arr[index], index + 1, dp);

	exc = subsetSumTD(arr, target, index + 1, dp);

	return dp[index][target] = (inc || exc);
}

//Bottom Up DP
//Time complexity - O(n*target)
//Space complexity - O(n*target)
bool subsetSumBU(vi &arr, int target)
{
	int n = arr.size();
	vvi dp(n + 1, vi(target + 1, 0)); //dp[i][j] represents whether there is a subset of sum j if you have first i items

	for (int i = 0; i <= n; i++)	dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int sum = 1; sum <= target; sum++)
		{
			int inc = 0, exc = 0;
			if (sum >= arr[i - 1])	inc = dp[i - 1][sum - arr[i - 1]];

			exc = dp[i - 1][sum];

			dp[i][sum] = (inc || exc);
		}
	}

	return dp[n][target];
}


int main()
{
	starter();

	int n, target;
	cin >> n >> target;

	vi arr(n);
	cin >> arr;

	vvi dp(n + 1, vi(target + 1, -1));

	cout << subsetSum(arr, target, 0) << " " << subsetSumTD(arr, target, 0, dp) << " " << subsetSumBU(arr, target);
	return 0;
}