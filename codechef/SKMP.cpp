/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)

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
		string s, p;
		cin >> s >> p;
		int i = 0, j = 0;
		while (i < p.size()) //Removing all chars of pattern from string s
		{
			if (p[i] == s[j])
			{
				s.erase(s.begin() + j);
				i++;
			}
			else
			{
				if (j < s.size() - 1 ) j++;
				else j = 0;
			}
		}
		sort(s.begin(), s.end()); //Sorting lexographically after removing all chars
		int flag, c = 0;
		for (i = 1; i < p.length(); i++)
		{
			if (p[i - 1] > p[i])
			{
				flag = 1;
				break;
			}
			else if (p[i - 1] < p[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			for (i = 0; i < s.length(); i++)
			{
				if (p[0] < s[i])
				{
					c = 1;
					s.insert(i, p);
					break;
				}
			}
		}
		else
		{
			for (i = 0; i < s.length(); i++)
			{
				if (p[0] <= s[i])
				{
					c = 1;
					s.insert(i, p);
					break;
				}
			}
		}
		if (c == 0)	s.insert(i, p);
		cout << s << endl;
	}
	return 0;
}