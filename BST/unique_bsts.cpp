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
	Also we can consider every node to be a root node
	Therefore

	f(n) = Σ (f(i-1) * f(n-i)); ,  1 <= i <= n

	Hence Proved
*/

//Recursive
//Time complexity - O(3^n), check stackoverflow
//Space complexity - O(n)

int uniqueBST(int n)
{
	if (n == 0 or n == 1)	return 1;

	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		count += uniqueBST(i - 1) * uniqueBST(n - i);
	}

	return count;
}

//Recursion with memoization
//Time complexity - O(n^2)
//Space complexity - O(n)

int uniqueBST_Memoization(int n, vi &dp)
{
	if (n == 0 or n == 1)	return 1;

	if (dp[n] != -1)	return dp[n];

	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		count += uniqueBST_Memoization(i - 1, dp) * uniqueBST_Memoization(n - i, dp);
	}

	return dp[n] = count;
}

//Tabulation
//Time complexity - O(n^2)
//Space complexity - O(n)

int uniqueBST_Tabulation(int n)
{
	if (n == 1)	return 1;

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

	cout << uniqueBST(n) << endl << uniqueBST_Memoization(n, dp) << endl << uniqueBST_Tabulation(n);

	return 0;
}