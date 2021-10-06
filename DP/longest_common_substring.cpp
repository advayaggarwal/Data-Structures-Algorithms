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

//Time complexity - O(2^n)
int longestCommonSubstring(string &s1, string &s2, int i, int j, int count)
{
	if (i == s1.size() or j == s2.size())	return count;

	if (s1[i] == s2[j])
	{
		count = longestCommonSubstring(s1, s2, i + 1, j + 1, count + 1);
	}

	count = max({count, longestCommonSubstring(s1, s2, i + 1, j, 0), longestCommonSubstring(s1, s2, i, j + 1, 0)});

	return count;
}

/*
int longestCommonSubstringTD(string &s1, string &s2, int i, int j, int count, vvi &dp)
{
	if (i == s1.size() or j == s2.size())	return count;

	if (dp[i][j] != -1)	return dp[i][j];

	if (s1[i] == s2[j])
	{
		count = longestCommonSubstringTD(s1, s2, i + 1, j + 1, count + 1, dp);
	}

	count = max({count, longestCommonSubstringTD(s1, s2, i + 1, j, 0, dp), longestCommonSubstringTD(s1, s2, i, j + 1, 0, dp)});

	return dp[i][j] = count;
}
*/

//Time complexity - O(m*n)
//Space complexity - O(m*n)
int longestCommonSubstringBU(string &s1, string &s2)
{
	int n1 = s1.size(), n2 = s2.size();

	vvi dp(n1 + 1, vi(n2 + 1, 0)); //dp[i][j] represents length of lc substring, where string1 ending at i and string2 ending at j
	//dp[i][j] contains length of longest common suffix of s1[0..i-1] and s2[0..j-1]

	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
		}
	}

	int ans = INT_MIN;
	for (auto v : dp)
	{
		ans = max(ans, *max_element(v.begin(), v.end()));
	}

	return ans;
}

int main()
{
	starter();

	string s1, s2;
	cin >> s1 >> s2;

	vvi dp(s1.size() + 1, vi(s2.size() + 1, -1));
	cout << longestCommonSubstring(s1, s2, 0, 0, 0) << " " << longestCommonSubstringBU(s1, s2);
	return 0;
}