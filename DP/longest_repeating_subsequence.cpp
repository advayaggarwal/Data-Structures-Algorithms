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

void printLRS(vvi &dp, string &s)
{
	int n = s.size();

	int i = n, j = n;
	string lrs;

	while (i > 0 and j > 0)
	{
		if (s[i - 1] == s[j - 1] && i != j)
		{
			lrs += s[i - 1];
			i--;
			j--;
		}

		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])	i--;
			else j--;
		}
	}

	reverse(lrs.begin(), lrs.end());

	cout << "Longest Repeating Subsequence is " << lrs << " which is of length ";
}

//LCS of s and s, such that i should not be equal to j
int lrs(string &s)
{
	int n = s.size();

	vvi dp(n + 1, vi(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i - 1] == s[j - 1] and i != j)	dp[i][j] = 1 + dp[i - 1][j - 1];

			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printLRS(dp, s);

	return dp[n][n];
}

int main()
{
	starter();

	string s;
	cin >> s;

	cout << lrs(s);

	return 0;
}