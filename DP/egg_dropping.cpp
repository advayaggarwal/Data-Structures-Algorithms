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

//Recursive
//Time complexity - O(2^(f*e)), where e = #eggs, f = #floors
int eggDrop(int eggs, int floors)
{
	if (eggs == 0 or floors == 0)	return 0;

	if (eggs == 1 or floors == 1)	return floors;

	int ans = INT_MAX;

	for (int f = 1; f <= floors; f++)
	{
		int temp = 1 + max(eggDrop(eggs, floors - f), eggDrop(eggs - 1, f - 1));

		ans = min(ans, temp);
	}

	return ans;
}

//Top Down DP
//Time complexity - O(e*(f^2))
//Space complexity - O(e*f)
int eggDropTD(int eggs, int floors, vvi &dp)
{
	if (eggs == 0 or floors == 0)	return 0;

	if (eggs == 1 or floors == 1)	return floors;
	if (dp[eggs][floors] != -1)	return dp[eggs][floors];

	int ans = INT_MAX;

	for (int f = 1; f <= floors; f++)
	{
		int temp = 1 + max(eggDropTD(eggs, floors - f, dp), eggDropTD(eggs - 1, f - 1, dp));

		ans = min(ans, temp);
	}

	return dp[eggs][floors] = ans;
}

int eggDropBU(int eggs, int floors)
{
	vvi dp(eggs + 1, vi(floors + 1, 0));

	for (int i = 1; i <= eggs; i++)
	{
		for (int j = 1; j <= floors; j++)
		{
			if (i == 1)
			{
				dp[i][j] = j;
			}

			else if (j == 1)
			{
				dp[i][j] = 1;
			}

			else
			{
				int ans = INT_MAX;
				for (int mj = j - 1, pj = 0; mj >= 0; mj--, pj++)
				{
					int val1 = dp[i][mj];
					int val2 = dp[i - 1][pj];
					ans = min(ans, max(val1, val2));
				}

				dp[i][j] = 1 + ans;
			}
		}
	}

	return dp[eggs][floors];
}

int main()
{
	starter();

	int eggs, floors;
	cin >> eggs >> floors;

	vvi dp(eggs + 1, vi(floors + 1, -1));
	cout << eggDrop(eggs, floors) << " " << eggDropTD(eggs, floors, dp) << " " << eggDropBU(eggs, floors);

	return 0;
}