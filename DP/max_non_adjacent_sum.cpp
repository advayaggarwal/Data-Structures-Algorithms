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
//Time complexity - O(2^n)
//Space complexity - O(n)
int maxNonAdjacentSum(vi &v, int index, int n)
{
	if (index == n - 1)	return v[index];
	if (index >= n)	return 0;


	int inc = v[index] + maxNonAdjacentSum(v, index + 2, n);
	int exc = maxNonAdjacentSum(v, index + 1, n);

	return max({0, inc, exc}); //0 considering negative elements
}

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
int maxNonAdjacentSumTD(vi &v, int index, int n, vi &dp)
{
	if (index == n - 1)	return v[index];
	if (index >= n)	return 0;

	if (dp[index] != -1)	return dp[index];

	int inc = v[index] + maxNonAdjacentSumTD(v, index + 2, n, dp);
	int exc = maxNonAdjacentSumTD(v, index + 1, n, dp);

	return dp[index] = max({0, inc, exc}); //0 considering negative elements
}

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
int maxNonAdjacentSumBU(vi &v, int n)
{
	vi dp(n, 0); //dp[i] denotes the maximum non adjacent sum you can get from 1st i+1 elements

	dp[0] = max(v[0], 0); //0 considering negative elements
	if (n > 1)	dp[1] = max({0, v[0], v[1]});

	for (int i = 2; i < n; i++)
	{
		int inc = v[i] + dp[i - 2];
		int exc = dp[i - 1];

		dp[i] = max(inc, exc);
	}

	return dp[n - 1];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi v(n);
	cin >> v;

	vi dp(n, -1);
	cout << maxNonAdjacentSum(v, 0, n) << " " << maxNonAdjacentSumTD(v, 0, n, dp) << " " << maxNonAdjacentSumBU(v, n);

	return 0;
}