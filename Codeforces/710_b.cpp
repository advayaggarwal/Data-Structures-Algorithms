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
		string s;
		cin >> s;

		int ans = 1;
		int i = s.find_first_of('*');
		//cout << i << endl;
		while (true)
		{
			int j = min(n - 1, i + k);

			for (; i < j && s[j] == '.'; j--) {}
			if (i == j) break;
			else
			{
				ans++;
				i = j;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
