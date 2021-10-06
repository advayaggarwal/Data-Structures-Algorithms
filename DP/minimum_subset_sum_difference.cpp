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

//Time complexity - O(n*sum)
vi subsetSumBU(vi &arr, int target)
{
	int n = arr.size();
	vvi dp(n + 1, vi(target + 1, 0));

	for (int i = 0; i <= n; i++)	dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int sum = 1; sum <= target; sum++)
		{
			int inc = 0, exc = 0;

			if (sum >= arr[i - 1])	inc = dp[i - 1][sum - arr[i - 1]];

			exc = dp[i - 1][sum];

			dp[i][sum] = inc || exc;
		}
	}
	return dp[n]; //We only need last row, i.e. answer corresponding to all the elements
}

//O(n*sum + sum)
int minDifference(vi &arr)
{
	int n = arr.size();
	int sum = 0;
	for (int e : arr)	sum += e;

	vi dp = subsetSumBU(arr, sum);

	int min_diff = INT_MAX;

	for (int i = sum / 2; i >= 0; i--)
	{
		if (dp[i] == 1)
		{
			min_diff = sum - 2 * i; //one subset sums to i and definitely other will be sum-i so difference would be sum-2*i
			break;
		}
	}

	return min_diff;
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi arr(n);
	cin >> arr;

	cout << minDifference(arr);

	return 0;
}