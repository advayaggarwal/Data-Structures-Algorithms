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


// //Recursion
// //Time complexity - O(2^n)
// //Space complexity - O(n)
int Knapsack(vi &value, vi &weight, int W, int n)
{
	if (n == 0 || W == 0)	return 0;

	int inc = 0, exc = 0;

	if (weight[n - 1] <= W)
	{
		inc = value[n - 1] + Knapsack(value, weight, W - weight[n - 1], n - 1);
	}

	exc = Knapsack(value, weight, W, n - 1);

	return max(inc, exc);
}

//Recursion with Memoization
//Time complexity - O(n*W)
//Space complexity - O(n*W)
int KnapsackTD(vi &value, vi &weight, int W, int n, vector<vi>dp) //TOP DOWN
{
	if (n == 0 || W == 0)	return 0;

	if (dp[n][W] != -1)	return dp[n][W];

	int inc = 0, exc = 0;

	if (weight[n - 1] <= W)
	{
		inc = value[n - 1] + KnapsackTD(value, weight, W - weight[n - 1], n - 1, dp);
	}

	exc = KnapsackTD(value, weight, W, n - 1, dp);

	return dp[n][W] = max(inc, exc);
}


//Iterative DP
//Time complexity - O(n*W)
//Space complexity - O(n*W)
int KnapsackBU(vi &value, vi &weight, int W, int n) //BOTTOM UP
{
	vvi dp(n + 1, vi(W + 1, 0)); //dp[i][j] represents max profit we can get if we have 1st i items and capacity of Knapsack is j
	for (int i = 1; i <= n; i++)
	{
		for (int w = 1; w <= W; w++)
		{
			int inc = 0, exc = 0;

			if (weight[i - 1] <= w)
			{
				inc = value[i - 1] + dp[i - 1][w - weight[i - 1]];
			}

			exc = dp[i - 1][w];

			dp[i][w] = max(inc, exc);
		}
	}

	return dp[n][W];
}


//Iterative DP with reduced space complexity
//Time complexity - O(n*W)
//Space complexity - O(W)
int KnapsackTabulationReducedSpace(vi &value, vi &weight, int W, int n, vi K) //BOTTOM UP
{
	for (int i = 0; i <= n; i++)
	{
		for (int w = W; w >= 0; w--)
		{
			if (weight[i - 1] <= w)
			{
				K[w] = max(K[w], K[w - weight[i - 1]] + value[i - 1]);
			}
		}
	}

	return K[W];
}


int main()
{
	starter();
	int n, W;
	cin >> n >> W;
	vi value(n), weight(n);
	cin >> value >> weight;

	cout << Knapsack(value, weight, W, n) << endl;

	vector<vi>dp(n + 1, vi(W + 1, -1));
	cout << KnapsackTD(value, weight, W, n, dp) << endl;

	cout << KnapsackBU(value, weight, W, n) << endl;

	vi K(W + 1, 0);
	cout << KnapsackTabulationReducedSpace(value, weight, W, n, K);

	return 0;
}