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
	Number of unique BSTs is equal to f(n), where f gives the Catalan number and n is number of nodes

	f(n) = Σ (f(i-1) * f(n-i)); ,  1 <= i <= n

	Proof:

	1 2 3 ... i .... n ->nodes

	Considering i as the root node: -
		* nodes 1 2 3 ... i-1 would come in left subtree -> i-1 nodes
		* nodes i+1 ... n would come in right subtree -> n-i nodes

	g(i) = f(i-1) * f(n-i),
	where g(i) gives the number of trees considering ith node as the root node
	Also we can consider every node from 1 to n as a root node

	Therefore

	f(n) = Σ (f(i-1) * f(n-i)); ,  1 <= i <= n

	Hence Proved
*/

//Recursive
//Time complexity - O(3^n), check stackoverflow
//Space complexity - O(n)
int uniqueBSTs(int n)
{
	if (n == 0 or n == 1)	return 1;

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans += uniqueBSTs(i - 1) * uniqueBSTs(n - i);
	}

	return ans;
}

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n)
int uniqueBSTsTD(int n, vi &dp)
{
	if (n == 0 or n == 1)	return 1;

	if (dp[n] != -1)	return dp[n];

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += uniqueBSTsTD(i - 1, dp) * uniqueBSTsTD(n - i, dp);
	}

	return dp[n] = ans;
}

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n)
int uniqueBSTsBU(int n)
{
	vi dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] += (dp[j - 1] * dp[i - j]);
		}
	}

	return dp[n];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi dp(n + 1, -1);

	cout << uniqueBSTs(n) << " " << uniqueBSTsTD(n, dp) << " " << uniqueBSTsBU(n);
	return 0;
}