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
		string s;
		cin >> s;
		unordered_map<char, int>m;
		for (int i = 0; i < (int)s.size(); i++)
		{
			m[s[i]]++;
		}
		int count_1 = 0, even_count = 0;
		for (auto e : m)
		{
			even_count += (e.second / 2);
			count_1 += (e.second % 2);
			// cout << e.first << " " << e.second << endl;
		}

		if (even_count >= count_1)	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}