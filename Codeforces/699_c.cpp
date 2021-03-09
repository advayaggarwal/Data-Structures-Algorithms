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
		int n, m;
		cin >> n >> m;
		vi a(n), b(n), c(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		set<int>required;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			required.insert(b[i]);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> c[i];
		}

		int differ = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])	differ++;
		}
		vi ans;
		if (differ > m)	cout << "NO" << endl;
		else
		{
			for (int i = 0; i < m; i++)
			{
				if (required.find(c[i]) != required.end())
				{
					for (int j = 0; j < n; j++)
					{
						if (a[j] != b[j] && c[i] == b[j])
						{
							ans.push_back(j + 1);
							break;
						}
					}
				}
				else
				{
					for (int j = 0; j < n; j++)
					{
						if (a[j] == c[i])
						{
							ans.push_back(j + 1);
							break;
						}
					}
				}
			}
			for (auto e : ans)	cout << e << " ";
			cout << endl;
		}

	}
	return 0;
}