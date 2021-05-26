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

bool isVowel(char c)
{
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'Y')	return true;
	return false;
}

int main()
{
	starter();
	string s;
	cin >> s;
	string ans = "";
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (isVowel(s[i]))	continue;
		else
		{
			ans += '.';
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				ans += 'a' + (s[i] - 'A');
			}
			else ans += s[i];
		}
	}
	cout << ans << endl;
	return 0;
}