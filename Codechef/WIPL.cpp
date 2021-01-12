/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}
bool dp[4001][4001];
void display(const vector<int>& v)
{
	for (int i = 0; i < int(v.size()); ++i)
		printf("%d ", v[i]);
	printf("\n");
}

void printSubsetsRec(int arr[], int i, int sum, vector<int>& p)
{
	// If we reached end and sum is non-zero. We print
	// p[] only if arr[0] is equal to sun OR dp[0][sum]
	// is true.
	if (i == 0 && sum != 0 && dp[0][sum])
	{
		p.push_back(arr[i]);
		display(p);
		return;
	}

	// If sum becomes 0
	if (i == 0 && sum == 0)
	{
		display(p);
		return;
	}

	// If given sum can be achieved after ignoring
	// current element.
	if (dp[i - 1][sum])
	{
		// Create a new vector to store path
		vector<int> b = p;
		printSubsetsRec(arr, i - 1, sum, b);
	}

	// If given sum can be achieved after considering
	// current element.
	if (sum >= arr[i] && dp[i - 1][sum - arr[i]])
	{
		p.push_back(arr[i]);
		printSubsetsRec(arr, i - 1, sum - arr[i], p);
	}
}

int main()
{
	starter();
	test_cases(t)
	{
		int n, k;
		cin >> n >> k;
		int H[n];
		ll int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> H[i];
			sum += H[i];
		}
		if (sum < (2 * k)) cout << -1 << endl;
		else
		{
			int blocks[n];
			sum = 0;
			sort(H, H + n, greater<int>());
			for (int i = 0; i < n; i++)
			{
				if (sum < (2 * k))
				{
					blocks[i] = H[i];
					sum += H[i];
				}
				else break;
			}
			cout << sum << endl;
			for (int i = 0; i <= n; i++)	dp[i][0] = true;
			for (int i = 1; i <= k ; i++)	dp[0][i] = false;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= k; j++)
				{
					// if (j >= blocks[i - 1])	dp[i][j] = dp[i - 1][j] | dp[i - 1][j - blocks[i - 1]];
					// else dp[i][j] = dp[i - 1][j];
					dp[i][j] = (blocks[i] <= j) ? dp[i - 1][j] || dp[i - 1][j - blocks[i]] : dp[i - 1][j];
				}
			}
			if (dp[n][k] == false)	cout << "Not possible";
			vi p;
			printSubsetsRec(blocks, n - 1, k, p);
		}
	}
	return 0;
}