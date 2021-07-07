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
// //Space complexity - O(1)
int Knapsack(vi &value, vi &weight, int W, int n)
{
	if (n == 0 || W == 0)	return 0;

	if (weight[n - 1] <= W)
	{
		return max(Knapsack(value, weight, W, n - 1), value[n - 1] + Knapsack(value, weight, W - weight[n - 1], n - 1));
	}

	else
	{
		return Knapsack(value, weight, W, n - 1);
	}
}

//Recursion with Memoization
//Time complexity - O(n*W)
//Space complexity - O(n*W)
int KnapsackMemoization(vi &value, vi &weight, int W, int n, vector<vi>dp) //TOP DOWN
{
	if (n == 0 || W == 0)
	{
		dp[n][W] = 0;
		return 0;
	}

	if (dp[n][W] != -1)	return dp[n][W];

	if (weight[n - 1] <= W)
	{
		return dp[n][W] = max(KnapsackMemoization(value, weight, W, n - 1, dp), value[n - 1] + KnapsackMemoization(value, weight, W - weight[n - 1], n - 1, dp));
	}

	else
	{
		return dp[n][W] = KnapsackMemoization(value, weight, W, n - 1, dp);
	}
}


//Iterative DP
//Time complexity - O(n*W)
//Space complexity - O(n*W)
int KnapsackTabulation(vi &value, vi &weight, int W, int n, vector<vi>dp) //BOTTOM UP
{
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)	dp[i][w] = 0;

			else if (weight[i - 1] <= w)
			{
				dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
			}

			else
			{
				dp[i][w] = dp[i - 1][w];
			}
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
	int n;
	cin >> n;
	vi value(n), weight(n);
	cin >> value >> weight;
	int W;
	cin >> W;
	cout << Knapsack(value, weight, W, n) << endl;
	vector<vi>dp(n + 1, vi(W + 1, -1));
	cout << KnapsackMemoization(value, weight, W, n, dp) << endl;
	cout << KnapsackTabulation(value, weight, W, n, dp) << endl;
	vi K(W + 1, 0);
	cout << KnapsackTabulationReducedSpace(value, weight, W, n, K) << endl;
	return 0;
}