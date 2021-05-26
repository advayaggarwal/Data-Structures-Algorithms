/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
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

int main()
{
	starter();
	test_cases(t)
	{
		int n, m, k;
		cin >> n >> m >> k;
		ll A[n + 1][m + 1];
		ll pre[n + 1][m + 1];
		ll count = 0;
		memset(&A, 0 , sizeof(A));
		memset(&pre, 0 , sizeof(pre));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> A[i][j];
				if (A[i][j] >= k)	count++;
				pre[i][j] = A[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			}
		}


		int mn = min(n, m);
		int order = 2;
		ll sum;
		while (order <= mn)
		{
			for (int i = order; i <= n; i++)
			{
				int j = m + 1;
				int low = order;
				int hi = m;
				while (low <= hi)
				{
					int mid = low + (hi - low) / 2;
					int a = i - order + 1;
					int b = mid - order + 1;
					sum = pre[i][mid] - pre[a - 1][mid] - pre[i][b - 1] + pre[a - 1][b - 1];
					if (sum / (order * 1LL * order) >= k)
					{
						j = mid;
						hi = mid - 1;
					}
					else low = mid + 1;
				}

				count += m - j + 1;
			}
			order ++;
		}

		cout << count << endl;
	}
	return 0;
}