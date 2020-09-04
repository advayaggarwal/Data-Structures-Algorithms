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

void toh(int n, char s, char d, char h)
{
	if (n == 1)
	{
		cout << "Move disk " << n << " from " << s << " to " << d << endl;
		return;
	}
	toh(n - 1, s, h, d);
	cout << "Move disk " << n << " from " << s << " to " << d << endl;
	toh(n - 1, h, d, s);
}

int main()
{
	starter();
	int n;
	cin >> n;
	toh(n, 's', 'd', 'h');
	return 0;
}