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

//Steps possible- 1, 2 and 3

int countWays(int n)
{
	if (n < 0)	return 0;
	if (n == 0 || n == 1)	return 1;

	return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int countWaysDp(int n, vi &dp)
{
	if (n == 0 || n == 1)
	{
		dp[n] = 1;
		return 1;
	}

	if (dp[n] != -1)	return dp[n];

	return dp[n] = countWaysDp(n - 1, dp) + countWaysDp(n - 2, dp) + countWaysDp(n - 3, dp);
}

int countWaysBottomUp(int n)
{
	vi dp(n + 1);
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}

int main()
{
	starter();
	int n;
	cin >> n;
	cout << countWays(n) << endl;
	vi dp(n + 1, -1);
	cout << countWaysDp(n, dp) << endl;
	cout << countWaysBottomUp(n) << endl;
	return 0;
}