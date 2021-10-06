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
Given an array sequence, find the length of the longest subsequence of such that the subsequence are sorted
in increasing order.
*/

//Recursion
//Time complexity - O(2^n)
int lis(vi &v, int index, int n, int prev) //Longest Increasing Subsequence
{
	if (index == n - 1)
	{
		if (v[index] > prev)	return 1;
		return 0;
	}

	int inc = 0;

	if (v[index] > prev)
	{
		inc = 1 + lis(v, index + 1, n, v[index]);
	}

	int exc = lis(v, index + 1, n, prev);

	return max(inc, exc);
}

/*
int lisTD(vi &v, int index, int n, int prev, vi &dp) //Longest Increasing Subsequence
{
	if (index == n - 1)
	{
		if (v[index] > v[prev])	return 1;
		return 0;
	}

	if (dp[index] != -1)	return dp[index];

	int inc = 0;

	if (v[index] > v[prev])
	{
		inc = 1 + lisTD(v, index + 1, n, index, dp);
	}

	int exc = lisTD(v, index + 1, n, prev, dp);

	return dp[index] = max(inc, exc);
}
*/

//Bottom Up DP
//Time complexity - O(n^2)
int lisBU(vi &v, int n)
{
	vi dp(n, 1); //dp[i] denotes the length of LIS ending at index i

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i])	dp[i] = max(dp[i], 1 + dp[j]);
		}
	}

	return *max_element(dp.begin(), dp.end());
}

//Time complexity - O(n*logn)
int lengthOfLIS(vector<int>& nums) {

	vector<int>sub;

	for (int num : nums)
	{
		if (sub.size() == 0 or sub[sub.size() - 1] < num)
		{
			sub.push_back(num);
		}

		else
		{
			int index = lower_bound(sub.begin(), sub.end(), num) - sub.begin();
			sub[index] = num;
		}
	}

	return sub.size();
}


int main()
{
	starter();

	int n;
	cin >> n;

	vi v(n);
	cin >> v;

	vi dp(n, -1);

	cout << lis(v, 0, n, INT_MIN) << " " << lisBU(v, n) << " " << lengthOfLIS(v);

	return 0;
}