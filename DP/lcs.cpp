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
#define vvi vector<vector<int>>

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
//Time complexity - O(2^n), n is max(s1.size(), s2.size())
//Space complexity - O(max(m,n))
int lcs(string &s1, string &s2, int i, int j)
{
	if (i == s1.size() or j == s2.size())	return 0;

	if (s1[i] == s2[j])	return 1 + lcs(s1, s2, i + 1, j + 1); //if current matches

	//if current doesn't match
	int op1 = lcs(s1, s2, i + 1, j);
	int op2 = lcs(s1, s2, i, j + 1);

	return max(op1, op2);
}

//Time complexity - O(m*n)
//Space complexity - O(m*n)
int lcsTD(string &s1, string &s2, int i, int j, vvi &dp)
{
	if (i == s1.size() or j == s2.size())	return 0;

	if (dp[i][j] != -1)	return dp[i][j]; //dp[i][j] denotes length of lcs of string 1(i...n1-1) and string 2(j...n2-1)

	if (s1[i] == s2[j])	return dp[i][j] = 1 + lcsTD(s1, s2, i + 1, j + 1, dp);

	int op1 = lcsTD(s1, s2, i + 1, j, dp);
	int op2 = lcsTD(s1, s2, i, j + 1, dp);

	return dp[i][j] = max(op1, op2);
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

int main()
{
	starter();

	string s1, s2;
	cin >> s1 >> s2;

	int n1 = s1.size(), n2 = s2.size();

	vvi dp(n1, vi(n2, -1)); //n1 X n2

	cout << lcs(s1, s2, 0, 0) << " " << lcsTD(s1, s2, 0, 0, dp) << endl;
	cout << lcsBU(s1, s2);

	return 0;
}