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

bool is_balanced(string s)
{
	stack<char> st;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')	st.push(s[i]);
		else
		{
			if (st.empty())	return false; //we can't check top if stack is empty
			if (s[i] == ')' && st.top() == '(')	st.pop();
			else if (s[i] == '}' && st.top() == '{')	st.pop();
			else if (s[i] == ']' && st.top() == '[')	st.pop();
			else return false;
		}
	}

	return st.empty();
}

int main()
{
	starter();
	test_cases(t)
	{
		string s;
		cin >> s;
		if (is_balanced(s))	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}