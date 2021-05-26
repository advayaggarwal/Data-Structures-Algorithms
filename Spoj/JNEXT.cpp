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
		int n;
		cin >> n;
		vi arr(n);
		for (int i = 0; i < n; i++)	cin >> arr[i];

		ll res = 0;
		ll b = 1;
		for (int j = n - 1; j >= 0; j--) {
			res += (arr[j] * b);
			b *= 10;
		}
		stack<pair<int, int>>s; //ele,index

		int i = n - 1;
		while (i >= 0)
		{
			if (s.empty())
			{
				s.push({arr[i], i});
				i--;
			}

			else if (s.top().first <= arr[i])
			{
				s.push({arr[i], i});
				i--;
			}
			else
			{
				swap(arr[i], arr[s.top().second]);
				i = s.top().second;
				s.pop();

				while (!s.empty() && s.top().first <= arr[i])
				{
					swap(arr[i], arr[s.top().second]);
					i = s.top().second;
					s.pop();
				}

				if (s.empty())	break;
			}
		}
		ll ans = 0;
		ll base = 1;
		for (int j = n - 1; j >= 0; j--) {
			ans += (arr[j] * base);
			base *= 10;
		}
		cout << (res == ans ? -1 : ans) << endl;
	}
	return 0;
}