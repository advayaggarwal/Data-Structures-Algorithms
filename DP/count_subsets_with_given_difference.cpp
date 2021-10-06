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

//Time complexity - O(n*target)
int countSubsets(vi &arr, int target)
{
	int n = arr.size();
	vvi dp(n + 1, vi(target + 1, 0));

	for (int i = 0; i <= n; i++)	dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= target; j++)
		{
			int inc = 0, exc = 0;

			if (j >= arr[i - 1])	inc = dp[i - 1][j - arr[i - 1]];

			exc = dp[i - 1][j];

			dp[i][j] = inc + exc;
		}
	}

	return dp[n][target];
}

/*
	Let us suppose the 2 subsets are s1 and s2
	So,

	s1 - s2 = difference (Given)
	s1 + s2 = sum
   +---------------- Adding both the equations
    2*s1 = sum + difference => s1 = (sum + difference)/2

    And, s2 = (sum-difference)/2

    Therefore question boils down to count the subsets with sum s1 or s2
*/

int countSubsetsWithGivenDifference(vi &arr, int difference)
{
	int sum = 0;

	for (int e : arr)	sum += e;

	return countSubsets(arr, (sum + difference) / 2);
}

int main()
{
	starter();

	int n, difference;
	cin >> n >> difference;

	vi arr(n);
	cin >> arr;

	cout << countSubsetsWithGivenDifference(arr, difference);

	return 0;
}