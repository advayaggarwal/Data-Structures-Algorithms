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

int weight(char x)
{
	if (x == '*' || x == '/')	return 1;
	if (x == '^')	return 2;
	else return 0;
}

bool higher_precedence(char a, char b)
{
	if (a == '^' && b == '^')	return false;
	if (weight(a) >= weight(b))	return true;
	//if ((a == '*' || a == '/') && (b == '+' || b == '-'))	return true;
	return false;
}

bool is_operand(char x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))	return true;
	return false;
}

bool is_operator(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')	return true;
	return false;
}

string infix_to_postfix(string &exp) //Time complexity - O(|exp|)
{
	string res;
	stack<char>s;

	for (int i = 0; i < (int)exp.size(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')	s.push(exp[i]);
		else if (is_operand(exp[i]))	res += exp[i];

		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			while (!s.empty() && is_operator(s.top()))
			{
				res += s.top();
				s.pop();
			}

			s.pop();
		}

		else if (is_operator(exp[i]))
		{
			while (!s.empty() && is_operator(s.top()) && higher_precedence(s.top(), exp[i]))
			{
				res += s.top();
				s.pop();
			}

			s.push(exp[i]);
		}
	}

	while (!s.empty())
	{
		res += s.top();
		s.pop();
	}

	return res;
}

int main()
{
	starter();
	test_cases(t)
	{
		string exp;
		cin >> exp;
		cout << infix_to_postfix(exp) << endl;
	}
	return 0;
}