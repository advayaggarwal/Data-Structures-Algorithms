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
//Time complexity - O(n^n)
int rodCutting(vi &price, int n)
{
	if (n == 0)	return 0;

	int ans = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		ans = max(ans, price[i] + rodCutting(price, n - i - 1));
	}

	return ans;
}

//Top Down DP
//Time complexity - O(n^2)
int rodCuttingTD(vi &price, int n, vi &dp)
{
	if (n == 0)	return 0;

	if (dp[n] != -1)	return dp[n];

	int ans = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		ans = max(ans, price[i] + rodCuttingTD(price, n - i - 1, dp));
	}

	return dp[n] = ans;
}

//Bottom Up DP
//Time complexity - O(n^2)
int rodCuttingBU(vi &price, int n)
{
	vi dp(n + 1, 0);

	for (int len = 1; len <= n; len++)
	{
		for (int i = 0; i < len; i++)
		{
			dp[len] = max(dp[len], price[i] + dp[len - i - 1]);
		}
	}

	return dp[n];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi price(n, 0);

	cin >> price;

	vi dp(n + 1, -1);
	cout << rodCutting(price, n) << " " << rodCuttingTD(price, n, dp) << " " << rodCuttingBU(price, n);

	return 0;
}