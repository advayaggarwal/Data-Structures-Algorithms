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

string LCS(string &s1, string &s2, int n1, int n2, vvi &dp)
{
	string s; //to store the lcs

	int i = n1, j = n2;
	while (i != 0 and j != 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			s += s1[i - 1];
			i--;
			j--;
		}

		else
		{
			if (dp[i][j] == dp[i - 1][j])	i--;

			else	j--;
		}
	}

	reverse(s.begin(), s.end());

	return s;
}

//Time complexity - O(m*n)
//Space complexity - O(m*n)
int lcsBU(string &s1, string &s2)
{
	int n1 = s1.size(), n2 = s2.size();

	vvi dp(n1 + 1, vi(n2 + 1, 0));

	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (s1[i - 1] == s2[j - 1])	dp[i][j] = 1 + dp[i - 1][j - 1];

			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << "Longest Common Subsequence is " << LCS(s1, s2, n1, n2, dp) << " which is of length ";

	return dp[n1][n2];
}

//Longest Palindromic Subsequence LPS
// LPS(a) = LCS(a, reverse(a))
int main()
{
	starter();

	string s;
	cin >> s;

	string s1 = s;
	reverse(s1.begin(), s1.end());

	cout << lcsBU(s, s1);

	return 0;
}
