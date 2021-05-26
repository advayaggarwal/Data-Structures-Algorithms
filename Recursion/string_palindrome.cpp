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

bool is_palindrome(string s, int i, int j)
{
	if (i >= j)	return true;
	if (s[i] == s[j])
	{
		return is_palindrome(s, ++i , --j);
	}

	else return false;

}

int main()
{
	starter();
	test_cases(t)
	{
		string s;
		cin >> s;
		if (is_palindrome(s, 0, s.size() - 1))	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}