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

void toLower(string &s)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')	s[i] = 'a' + (s[i] - 'A');
	}
}

int main()
{
	starter();
	string a, b;
	cin >> a >> b;

	toLower(a);
	toLower(b);

	if (a == b)	cout << 0 << endl;
	else if (a > b)	cout << 1 << endl;
	else cout << -1 << endl;

	return 0;
}