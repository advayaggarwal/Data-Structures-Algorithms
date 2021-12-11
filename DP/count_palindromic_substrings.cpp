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

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
int main()
{
	starter();

	string s;
	cin >> s;

	int n = s.size();

	vector<vector<bool>>dp(n, vector<bool>(n, false)); //dp[i][j] represents whether s.substr(i, j-i+1) is a palindrome or not

	int count = 0;
	for (int gap = 0; gap < n; gap++)
	{
		for (int i = 0, j = gap; i < n; i++, j++)
		{
			if (gap == 0)	dp[i][j] = true;

			else if (gap == 1)
			{
				dp[i][j] = (s[i] == s[j]) ? true : false;
			}

			else
			{
				dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
			}

			if (dp[i][j])	count++;
		}
	}

	cout << count;

	return 0;
}