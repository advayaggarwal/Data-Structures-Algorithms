/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)

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
		int n, i, j, ans = 0;
		cin >> n;
		int arr[n][n];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)		cin >> arr[i][j];
		}
		for (j = n - 1; j > 0 ; j--)
		{
			if (arr[0][j] != j + 1)
			{
				for (i = 0; i < n; i++)
				{
					for (int k = i + 1; k < n; k++)
					{
						int temp = arr[i][k];
						arr[i][k] = arr[k][i];
						arr[k][i] = temp;
					}
				}
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}