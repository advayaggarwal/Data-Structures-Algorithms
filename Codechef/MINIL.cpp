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

int main()
{
	starter();
	test_cases(t)
	{
		int n, m;
		cin >> n >> m;
		char s[n][m];
		//vector<string> s;
		for (int i = 0; i < n; i++)
		{
			// string x;
			// cin >> x;
			// s.push_back(x);
			for (int j = 0; j < m; j++)
			{
				char x;
				cin >> x;
				s[i][j] = x;
			}
		}

		int count = 0, count1 = 0;
		int flag = 1;
		//1->* -1->.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (flag == 1)
				{
					if (s[i][j] == '.')
					{
						count++;
					}
					flag = -1;
				}
				else
				{
					if (s[i][j] == '*')
					{
						count++;
					}
					flag = 1;
				}
			}
			if (!(m & 1))	flag = flag * -1;
		}

		flag = -1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (flag == 1)
				{
					if (s[i][j] == '.')
					{
						count1++;
					}
					flag = -1;
				}
				else
				{
					if (s[i][j] == '*')
					{
						count1++;
					}
					flag = 1;
				}
			}
			if (!(m & 1))	flag = flag * -1;
		}
		//cout << count << " " << count1 << endl;
		if ((n * m) % 2 == 1)	cout << count << endl;
		else cout << min(count, count1) << endl;
	}
	return 0;
}