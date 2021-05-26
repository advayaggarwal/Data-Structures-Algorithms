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
	string s;
	cin >> s;
	int n = s.size();
	int arr[4] = {0};

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1' || s[i] == '2' || s[i] == '3')	arr[s[i] - '0']++;
	}

	int plus = n - (arr[1] + arr[2] + arr[3]);

	while (arr[1]--)
	{
		cout << 1;
		if (plus--)	cout << '+';
	}

	while (arr[2]--)
	{
		cout << 2;
		if (plus--)	cout << '+';
	}

	while (arr[3]--)
	{
		cout << 3;
		if (plus--)	cout << '+';
	}

	//cout << arr[1] << " " << arr[2] << " " << arr[3];
	return 0;
}