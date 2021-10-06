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

bool isPalindrome(string s, int i, int j)
{
	while (i < j)
	{
		if (s[i++] != s[j--])	return false;
	}

	return true;
}

//Time complexity - O(2^n)
//Space complexity - O(n)
int minPartitions(string &s, int i, int j)
{
	if (i >= j)	return 0;

	if (isPalindrome(s, i, j))	return 0;

	int ans = INT_MAX;

	for (int k = i; k < j; k++)
	{
		int temp = minPartitions(s, i, k) + minPartitions(s, k + 1, j) + 1;
		ans = min(ans, temp);
	}

	return ans;
}

//Time complexity - O(n^3), O(n) per state and total O(n^2) states
//Space complexity - O(n^2)
int minPartitionsTD(string &s, int i, int j, vvi &dp)
{
	if (i >= j)	return 0;
	if (dp[i][j] != -1)	return dp[i][j];

	if (isPalindrome(s, i, j))	return 0;

	int ans = INT_MAX;

	for (int k = i; k < j; k++)
	{
		int temp = minPartitionsTD(s, i, k, dp) + minPartitionsTD(s, k + 1, j, dp) + 1;
		ans = min(ans, temp);
	}

	return dp[i][j] = ans;
}

//Time complexity - O(n^2), O(n) per state and total O(n) states
//Space complexity - O(n)
int minPartitionsTDOptimised(string &s, int i, int n, vi &table)
{
	if (i >= n)	return 0;

	if (table[i] != -1)	return table[i];

	int ans = INT_MAX;

	for (int k = i; k < n; k++)
	{
		if (isPalindrome(s, i, k)) //only checking for the prefixes which are palindrome
		{
			ans = min(ans, minPartitionsTDOptimised(s, k + 1, n, table));
		}
	}

	return table[i] = 1 + ans;
}

//Minimize the partition such that all substrings are palindrome
int main()
{
	starter();

	string s;
	cin >> s;

	int n = s.size();

	vvi dp(n + 1, vi(n + 1, -1));
	cout << minPartitions(s, 0, n - 1) << " " << minPartitionsTD(s, 0, n - 1, dp) << endl;

	vi table(n + 1, -1);

	cout << minPartitionsTDOptimised(s, 0, n, table) - 1;
	//it is considering partition after last element also that's why we are subtracting 1, eg- abccbc -> a|bccb|c|

	return 0;
}