/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>


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

/*
Given an array sequence, find the length of the longest subsequence of such that the subsequence are sorted
in increasing order.
*/

//Recursion
//Time complexity - O(2^n)
int lis(vi &v, int index, int n, int prev) //Longest Increasing Subsequence
{
	if (index >= n)		return 0;

	int inc = 0;

	if (v[index] > prev)
	{
		inc = 1 + lis(v, index + 1, n, v[index]);
	}

	int exc = lis(v, index + 1, n, prev);

	return max(inc, exc);
}

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
int lisTD(vi &v, int index, int n, int prev, vvi &dp)
{
	if (index >= n)	return 0;

	if (prev != -1 && dp[index][prev] != -1)	return dp[index][prev];

	int inc = 0;

	if (prev == -1 or v[index] > v[prev]) //prev -1 means no elements have been included yet
	{
		inc = 1 + lisTD(v, index + 1, n, index, dp);
	}

	int exc = lisTD(v, index + 1, n, prev, dp);

	if (prev != -1)	dp[index][prev] = max(inc, exc);

	return max(inc, exc);
}

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n)
int lis(vi &v, int i, vi &dp)
{
	if (dp[i] != -1)	return dp[i];
	int ans = 1;
	for (int j = 0; j < i; j++)
	{
		if (v[i] > v[j])	ans = max(ans, lis(v, j, dp) + 1);
	}

	return dp[i] = ans;
}

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n)
int lisBU(vi &v, int n)
{
	vi dp(n, 1); //dp[i] denotes the length of LIS ending at index i
	vi hash(n); //for printing LIS
	for (int i = 1; i < n; i++)
	{
		hash[i] = i;
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i] && 1 + dp[j] > dp[i])
			{
				dp[i] = 1 + dp[j];
				hash[i] = j;
			}
		}
	}

	//Using hash vector we can print the LIS

	int lisLength = 0, lastIndex;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > lisLength)
		{
			lisLength = dp[i];
			lastIndex = i;
		}
	}

	vi lis;
	lis.push_back(v[lastIndex]);
	while (hash[lastIndex] != lastIndex)
	{
		lastIndex = hash[lastIndex];
		lis.push_back(v[lastIndex]);
	}

	reverse(lis.begin(), lis.end());
	cout << "LIS is " << lis << endl;
	return lisLength;
}

//Using Binary Search
//Time complexity - O(n*logn)
//Space complexity - O(n)
int lengthOfLIS(vector<int>& nums) {

	vector<int>sub;

	for (int num : nums)
	{
		if (sub.size() == 0 or sub[sub.size() - 1] < num)
		{
			sub.push_back(num);
		}

		else
		{
			//for non-decreasing use upper_bound
			int index = lower_bound(sub.begin(), sub.end(), num) - sub.begin();
			sub[index] = num;
		}
	}

	return sub.size();
}

int getBestCandidate(map<int, int>&candidates, int num)
{
	auto it = candidates.lower_bound(num);
	if (it == candidates.begin())	return 0;

	it--;

	return it->second;
}

void insert(map<int, int>&candidates, int num, int advantage)
{
	if (candidates[num] >= advantage)	return;

	candidates[num] = advantage;

	auto it = candidates.find(num);
	it++;

	while (it != candidates.end() && it->second <= advantage)
	{
		auto temp = it;
		it++;

		candidates.erase(temp);
	}
}

int legnthLIS(vector<int>&v, int n)
{
	int dp[n];
	dp[0] = 1; //dp[i] denotes the length of LIS ending at index i

	map<int, int>candidates; //{num, length of lis ending at num}
	candidates[v[0]] = 1;

	for (int i = 1; i < n; i++)
	{
		dp[i] = 1 + getBestCandidate(candidates, v[i]); //maximum number smaller than nums[i] with best advantage
		insert(candidates, v[i], dp[i]);
	}

	return *max_element(dp, dp + n);
}


int main()
{
	starter();

	int n;
	cin >> n;

	vi v(n);
	cin >> v;

	vvi dp(n, vi(n, -1));

	cout << lis(v, 0, n, INT_MIN) << " " << lisTD(v, 0, n, -1, dp) << " " << lisBU(v, n) << " " << lengthOfLIS(v) << " " << legnthLIS(v, n);

	return 0;
}