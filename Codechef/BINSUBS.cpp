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
		cin.ignore();
		string s;
		cin >> s;
		int ones[n] = {0};
		int one_so_far = 0;
		int zero_so_far = 0;
		int zeroes[n] = {0};

		for (int i = 0; i < n; i++)
		{
			ones[i] = one_so_far;
			if (s[i] == '1')
			{
				one_so_far++;
			}
		}

		for (int i = n - 1;  i >= 0; i--)
		{
			zeroes[i] = zero_so_far;
			if (s[i] == '0')
			{
				zero_so_far++;
			}
		}

		int min = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (zeroes[i] + ones[i] < min)	min = zeroes[i] + ones[i];
		}
		cout << min << endl;
	}
	return 0;
}