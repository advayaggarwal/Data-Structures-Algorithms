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

vector<int> stock_span(int arr[], int n)
{
	stack<pair<int, int>>s; //{element,index}
	vi v; //for storing indices of nearest greater to left
	for (int i = 0; i < n; i++)
	{
		if (s.size() == 0)	v.push_back(-1);
		else if (s.top().first > arr[i])	v.push_back(s.top().second);
		else
		{
			while (s.size() != 0 && s.top().first <= arr[i])	s.pop();
			if (s.size() == 0)	v.push_back(-1);
			else v.push_back(s.top().second);
		}
		s.push({arr[i], i});
	}

	for (int i = 0; i < n; i++)
	{
		v[i] =  i - v[i];
	}
	return v;
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)	cin >> arr[i];
	vi v = stock_span(arr, n);
	for (auto e : v)	cout << e << " ";
	return 0;
}