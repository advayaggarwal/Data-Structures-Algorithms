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

//Time complexity - exponential
int mcm(vi &arr, int i, int j)
{
	if (i >= j)	return 0; //We need two dimensions to make a matrix

	int ans = INT_MAX;

	for (int k = i; k <= j - 1; k++)
	{
		int subProblem1 = mcm(arr, i, k);
		int subProblem2 = mcm(arr, k + 1, j);
		int cost = arr[i - 1] * arr[k] * arr[j]; //cost of multiplying two matrices (i...k) and (k+1...j)

		/*

								   sP1     sP2
									|		|
									v       v
		Total cost of multiplying (i...k)*(k+1...j) = sP1 + sP2 + cost
		                                 ^
			       						 |
										cost

		*/

		ans = min(ans, subProblem1 + subProblem2 + cost);
	}

	return ans;
}

//Time complexity - O(n^3), O(n) work in each n^2 states
//Space complexity - O(n^2)
int mcmTD(vi &arr, int i, int j, vvi &dp)
{
	if (i >= j)	return 0; //We need two dimensions to make a matrix

	if (dp[i][j] != -1)	return dp[i][j];

	int ans = INT_MAX;

	for (int k = i; k <= j - 1; k++)
	{
		int subProblem1 = mcmTD(arr, i, k, dp);
		int subProblem2 = mcmTD(arr, k + 1, j, dp);
		int cost = arr[i - 1] * arr[k] * arr[j]; //cost of multiplying two matrices (i...k) and (k+1...j)

		/*

								   sP1     sP2
									|		|
									v       v
		Total cost of multiplying (i...k)*(k+1...j) = sP1 + sP2 + cost
		                                 ^
			       						 |
										cost

		*/

		ans = min(ans, subProblem1 + subProblem2 + cost);
	}

	return dp[i][j] = ans;
}

int mcmBU(vi &arr)
{
	int n = arr.size();

	vvi dp(n, vi(n, 0));

	for (int len = 2; len < n; len++) //no of matrices to be multiplied i.e. chain length
	{
		for (int i = 1; i <= n - len; i++)
		{
			int j = i + len - 1;
			dp[i][j] = INT_MAX;

			for (int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
			}
		}
	}

	return dp[1][n - 1];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi arr(n);
	cin >> arr;

	//Dimensions of matrix Ai will be arr[i-1]*arr[i], 1 <= i <= n-1
	//For array of size n total matrices will be n-1

	vvi dp(n + 1, vi(n + 1, -1));
	cout << mcm(arr, 1, n - 1) << " " << mcmTD(arr, 1, n - 1, dp) << " " << mcmBU(arr);

	return 0;
}