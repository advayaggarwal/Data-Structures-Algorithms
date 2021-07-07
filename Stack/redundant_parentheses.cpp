/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; cin.ignore(); while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

bool checkRedundant(string s)
{
	stack<char>st;

	for (auto ch : s)
	{
		if (ch != ')')	st.push(ch); //push every char other than ')'
		else
		{
			bool operator_found = false;

			while (!st.empty() and st.top() != '(')
			{
				if (isOperator(st.top()))	operator_found = true;
				st.pop();
			}

			st.pop(); //pop the opening bracket after the loop is over

			if (!operator_found)	return true;
		}
	}

	return false;
}

int main()
{
	starter();
	test_cases(t)
	{
		string s;
		getline(cin, s);
		cout << s << endl;
		if (checkRedundant(s))	cout << "Contains Redundant Parentheses" << endl;
		else cout <<	"Doesn't contain Redundant Parentheses" << endl;
	}
	return 0;
}