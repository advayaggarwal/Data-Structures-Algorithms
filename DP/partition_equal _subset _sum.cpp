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

//Given a non-empty array nums containing only positive integers, find if the array can be partitioned
//into two subsets such that the sum of elements in both subsets is equal.

//Recursive
//Time complexity - O(2^n)
//Space complexity - O(n)
bool equalSumPartitionUtil(vi &arr, int target, int index)
{
	if (index == arr.size())	return false;

	if (target == 0)	return true;

	bool inc = false, exc = false;

	if (target >= arr[index]) inc = equalSumPartitionUtil(arr, target - arr[index], index + 1);
	exc = equalSumPartitionUtil(arr, target, index + 1);

	return (inc || exc);
}

//Top Down DP
//Time complexity - O(n*target)
//Space complexity - O(n*target)
bool equalSumPartitionTD(vi &arr, int target, int index, vvi &dp)
{
	if (index == arr.size())	return false;

	if (target == 0)	return true;

	if (dp[index][target] != -1)	return dp[index][target];
	bool inc = false, exc = false;

	if (target >= arr[index]) inc = equalSumPartitionUtil(arr, target - arr[index], index + 1);
	exc = equalSumPartitionUtil(arr, target, index + 1);

	return dp[index][target] = (inc || exc);
}

//Bottom Up DP
//Time complexity - O(n*target)
//Space complexity - O(n*target)
bool equalSumPartitionBU(vi &arr, int target)
{
	int n = arr.size();
	vvi dp(n + 1, vi(target + 1, 0));

	for (int i = 0; i <= n; i++)	dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int sum = 1; sum <= target; sum++)
		{
			if (sum >= arr[i - 1])
			{
				dp[i][sum] = dp[i - 1][sum - arr[i - 1]] || dp[i - 1][sum];
			}

			else
			{
				dp[i][sum] = dp[i - 1][sum];
			}
		}
	}

	return dp[n][target];
}

void equalSumPartition(vi &arr)
{
	int n = arr.size();
	int sum = 0;

	for (int num : arr)	sum += num;

	if (sum % 2 != 0)	cout << "Not possible"; //if sum is odd we can't divide it into 2 equal parts

	else
	{
		//if we get one partition of sum/2 then definitely other partition will also be sum/2
		cout << equalSumPartitionUtil(arr, sum / 2, 0) << endl;

		vvi dp(n + 1, vi(sum / 2 + 1, -1));

		cout << equalSumPartitionTD(arr, sum / 2, 0, dp) << endl << equalSumPartitionBU(arr, sum / 2);
	}
}




int main()
{
	starter();

	int n;
	cin >> n;

	vi arr(n);
	cin >> arr;

	equalSumPartition(arr);

	return 0;
}