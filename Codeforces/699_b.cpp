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
		int n, k;
		cin >> n >> k;
		int h[n];
		for (int i = 0; i < n; i++)	cin >> h[i];
		vi boulder;
		int b = k;
		while (b--)
		{
			bool ans = false;
			for (int i = 0; i < n - 1; i++)
			{
				if (h[i] >= h[i + 1])
				{
					continue;
				}
				else if (h[i] < h[i + 1])
				{
					h[i] += 1;
					ans = true;
					boulder.push_back(i + 1);
					break;
				}
			}
			if (!ans)	break;
		}

		if ((int)boulder.size() == k)	cout << boulder[k - 1] << endl;
		else cout << -1 << endl;
		// for (int i = 0; i < n; i++)	cout << h[i] << " ";
		// cout << endl;
		// for (auto &e : boulder)	cout << e << " ";
		// cout << endl;
	}
	return 0;
}