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
		double k1, k2, k3, v;
		cin >> k1 >> k2 >> k3 >> v;
		double speed = k1 * k2 * k3 * v;

		double time_taken = 100.00 / speed;
		cout << fixed << setprecision(2);
		//cout << time_taken << endl;
		if (time_taken >= 9.575)	cout << "NO" << endl;
		else cout << "YES" << endl;

	}
	return 0;
}