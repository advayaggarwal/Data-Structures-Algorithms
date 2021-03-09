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
		bool possible = false;
		if ((m['A'] == (m['B'] + m['C'])) || (m['B'] == (m['A'] + m['C'])) || (m['C'] == (m['B'] + m['A'])))	possible = true;
		char start = s[0];
		if (possible)
		{
			if (m[start] == (int)s.size() / 2)
			{
				stack<char>st;
				for (int i = 0; i < (int)s.size(); i++)
				{
					if (s[i] == start)	st.push(s[i]);
					else
					{
						if (st.size() == 0)
						{
							possible = false;
							break;
						}
						else	st.pop();
					}
				}

				if (possible)	cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else
			{
				char end;
				if (start == 'A' && (m['A'] + m['B'] == m['C']))	end = 'C';
				else if (start == 'A' && (m['A'] + m['C'] == m['B']))	end = 'B';
				else if (start == 'B' && (m['A'] + m['B'] == m['C']))	end = 'C';
				else if (start == 'B' && (m['C'] + m['B'] == m['A']))	end = 'A';
				else if (start == 'C' && (m['A'] + m['C'] == m['B']))	end = 'B';
				else end = 'A';
				stack<char>st;
				for (int i = 0; i < (int)s.size(); i++)
				{
					if (s[i] != end)	st.push(s[i]);
					else
					{
						if (st.size() == 0)
						{
							possible = false;
							break;
						}
						else	st.pop();
					}
				}

				if (possible)	cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
		else cout << "NO" << endl;
	}
	return 0;
}