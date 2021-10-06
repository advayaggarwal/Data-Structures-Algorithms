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
//Time complexity - O(2^(n1*n2))
int subsequenceCount(string &s1, string &s2, int i, int j)
{
	if ((i == -1 and j == -1) or j == -1)	return 1;
	if (i == -1)	return 0;

	if (s1[i] == s2[j])
	{
		return subsequenceCount(s1, s2, i - 1, j - 1) + subsequenceCount(s1, s2, i - 1, j);
	}

	return subsequenceCount(s1, s2, i - 1, j);
}

//Top Down DP
//Time complexity - O(n1*n2)
int subsequenceCountTD(string &s1, string &s2, int i, int j, vvi &dp)
{
	if ((i == -1 and j == -1) or j == -1)	return 1;
	if (i == -1)	return 0;

	if (dp[i][j] != -1)	return dp[i][j];

	if (s1[i] == s2[j])
	{
		return dp[i][j] = subsequenceCountTD(s1, s2, i - 1, j - 1, dp) + subsequenceCountTD(s1, s2, i - 1, j, dp);
	}

	return dp[i][j] = subsequenceCountTD(s1, s2, i - 1, j, dp);
}

//Bottom Up DP
//Time complexity - O(n1*n2)
int subsequenceCountBU(string &s1, string &s2)
{
	int n1 = s1.size(), n2 = s2.size();
	vvi dp(n1 + 1, vi(n2 + 1, 0));

	for (int i = 0; i <= n1; i++)	dp[i][0] = 1; //s2 is empty "", so if s1 is "" or not empty string we can have 1 way

	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}

			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n1][n2];
}

int main()
{
	starter();

	string s1, s2;
	cin >> s1 >> s2;

	int n1 = s1.size(), n2 = s2.size();
	vvi dp(n1, vi(n2, -1));
	cout << subsequenceCount(s1, s2, n1 - 1, n2 - 1) << " " << subsequenceCountTD(s1, s2, n1 - 1, n2 - 1, dp) << " " << subsequenceCountBU(s1, s2);

	return 0;
}