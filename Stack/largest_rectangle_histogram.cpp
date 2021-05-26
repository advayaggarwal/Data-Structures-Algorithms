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

vi nsl(int arr[], int n) //Nearest smaller to left
{
	stack<int>s; //{index}
	vi v;
	for (int i = 0; i < n; i++)
	{
		if (s.size() == 0)	v.push_back(-1);
		else if (arr[s.top()] < arr[i])	v.push_back(s.top());
		else
		{
			while (s.size() != 0 && arr[s.top()] >= arr[i])	s.pop();
			if (s.size() == 0)	v.push_back(-1);
			else v.push_back(s.top());
		}
		s.push(i);
	}
	return v;
}

vi nsr(int arr[], int n) //Nearest smaller to right
{
	stack<int>s; //{index}
	vi v;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.size() == 0)	v.push_back(n);
		else if (arr[s.top()] < arr[i])	v.push_back(s.top());
		else
		{
			while (s.size() != 0 && arr[s.top()] >= arr[i])	s.pop();
			if (s.size() == 0)	v.push_back(n);
			else v.push_back(s.top());
		}
		s.push(i);
	}
	reverse(v.begin(), v.end());
	return v;
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n]; //height
	for (int i = 0; i < n; i++)	cin >> arr[i];
	vi left_index = nsl(arr, n);
	vi right_index = nsr(arr, n);
	ll max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		//cout << arr[i]*(right_index[i] - left_index[i] - 1) << " "; //height * width
		if (arr[i] * (right_index[i] - left_index[i] - 1) > max)	max = arr[i] * (right_index[i] - left_index[i] - 1);
	}
	cout << max;
	return 0;
}