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
	//for getting input from input1.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output.txt", "w", stdout);
#endif
}

void solve(vector<string>&v, int open, int closed, string op) // We will have n open brackets and n closed brackets
{
	if (open == 0 && closed == 0)
	{
		//cout << "\"" << op << "\"" << endl;
		v.push_back(op);
		return ;
	}
	string op1 = op;
	string op2 = op;
	/*if (open == closed)
	{
		op1.push_back('(');
		solve(v, open - 1, closed, op1);
	}
	else if ((open < closed) && (open != 0)) // we can see that we push ( everytime when open is not 0 therefore we have used method 2
	{
		op1.push_back('(');
		solve(v, open - 1, closed, op1);
		op2.push_back(')');
		solve(v, open, closed - 1, op2);
	}
	else //open is zero
	{
		op1.push_back(')');
		solve(v, open , closed - 1, op1);
	}*/
	if (open != 0)
	{
		op1.push_back('(');
		solve(v, open - 1, closed, op1);
	}
	if (open < closed)
	{
		op2.push_back(')');
		solve(v, open, closed - 1, op2);
	}
	return;
}

vector<string> balanced_parentheses(int n)
{
	vector<string>v;
	int open = n;
	int closed = n;
	string op = "";
	solve(v, open, closed, op);
	return v;
}

int main()
{
	starter();
	int n;
	cin >> n;
	vector<string>v;
	v = balanced_parentheses(n);
	for (int i = 0; i < v.size(); i++)	cout << v.at(i) << endl;
	return 0;
}