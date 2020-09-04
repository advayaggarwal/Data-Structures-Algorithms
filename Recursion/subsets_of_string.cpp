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

void solve(string ip, string op)
{
	if (ip.length() == 0)
	{
		cout << "\"" << op << "\"" << endl ;
		return;
	}
	string op1 = op;
	string op2 = op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin() + 0);
	solve(ip, op1);
	solve(ip, op2);
	return;
}

int main()
{
	starter();
	string ip, op = "";
	cin >> ip;
	solve(ip, op);
	return 0;
}