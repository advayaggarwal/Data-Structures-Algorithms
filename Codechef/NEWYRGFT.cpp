#include <bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
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

const int N = 1e6 + 1;
int dp[N];

void getMinSquares()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i < N; i++)	dp[i] = i;
	for (int i = 2; i * i < N; i++)	dp[i * i] = 1;
	for (int i = 4; i < N ; i++)
	{
		if (dp[i] == 1)	continue;
		for (int x = 1; x <= ceil(sqrt(i)); x++)
		{
			int temp = x * x;
			if (temp > i)	break;
			else	dp[i] = min(dp[i], 1 + dp[i - temp]);
		}
	}
}

int main()
{
	starter();
	getMinSquares();
	test_cases(t)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}