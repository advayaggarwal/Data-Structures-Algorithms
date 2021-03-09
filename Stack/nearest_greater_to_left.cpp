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
#define pb push_back

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
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)	cin >> arr[i];
	vi v;
	stack<int>s;
	for (int i = 0; i < n; i++)
	{
		if (s.size() == 0)	v.pb(-1);
		else if (s.top() > arr[i])	v.pb(s.top());
		else
		{
			while (s.size() != 0 && s.top() <= arr[i])	s.pop();
			if (s.size() == 0)	v.pb(-1);
			else v.pb(s.top());
		}
		s.push(arr[i]);
	}

	for (int ele : v)	cout << ele << " ";
	return 0;
}