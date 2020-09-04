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

void solve(vector<string>&v, int ones, int zeroes, int n, string op)
{
	if (n == 0)
	{
		v.push_back(op);
		return;
	}
	string op1 = op;
	string op2 = op;
	op1.push_back('1');
	solve(v, ones + 1, zeroes, n - 1, op1);
	if (ones > zeroes) //then only we can push 0 as already #1s = #0s so if we push one more 0 it will violate our condition
	{
		op2.push_back('0');
		solve(v, ones, zeroes + 1, n - 1, op2);
	}
	return;
}

vector<string> nBit(int n)
{
	int ones = 0;
	int zeroes = 0;
	vector<string> v;
	string op = "";
	solve(v, ones, zeroes, n, op);
	return v;
}

int main()
{
	starter();
	int n;
	cin >> n;
	vector<string> v = nBit(n);
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << endl;
	return 0;
}