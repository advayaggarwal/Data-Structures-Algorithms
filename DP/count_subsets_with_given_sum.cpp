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

//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
int countSubsets(vi &arr, int target, int index)
{
	if (index == arr.size())
	{
		return target == 0 ? 1 : 0;
	}

	int inc = 0;
	if (target >= arr[index]) inc = countSubsets(arr, target - arr[index], index + 1);
	int exc = countSubsets(arr, target, index + 1);

	return inc + exc;
}

//Top Down DP
//Time complexity - O(n*target)
//Space complexity - O(n*target)
int countSubsetsTD(vi &arr, int target, int index, vvi &dp)
{
	if (index == arr.size())
	{
		return target == 0 ? 1 : 0;
	}

	if (dp[index][target] != -1)	return dp[index][target];

	int inc = 0;
	if (target >= arr[index]) inc = countSubsetsTD(arr, target - arr[index], index + 1, dp);
	int exc = countSubsetsTD(arr, target, index + 1, dp);

	return dp[index][target] = (inc + exc);
}

//Bottom Up DP
//Time complexity - O(n*target)
//Space complexity - O(n*target)
int countSubsetsBU(vi &arr, int target)
{
	int n = arr.size();
	vvi dp(n + 1, vi(target + 1, 0));

	for (int i = 0; i <= n; i++)	dp[i][0] = 1; //no of subsets with sum = 0 is 1 i.e. {}, empty subset

	for (int i = 1; i <= n; i++)
	{
		for (int sum = 1; sum <= target; sum++)
		{
			int inc = 0, exc = 0;

			if (sum >= arr[i - 1])	inc = dp[i - 1][sum - arr[i - 1]];

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

	vi arr(n);
	cin >> arr;

	vvi dp(n + 1, vi(target + 1, -1));
	cout << countSubsets(arr, target, 0) << " " << countSubsetsTD(arr, target, 0, dp) << " " << countSubsetsBU(arr, target);

	return 0;
}