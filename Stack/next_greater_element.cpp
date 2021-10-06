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

void brute_force(int arr[], int n) //Time complexity- O(n^2), Space complexity - O(1)
{
	int flag;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[i])
			{
				cout << arr[j] << " ";
				flag = 1;
				break;
			}
		}
		if (flag == 0)	cout << -1 << " ";
	}
}

void optimised(int arr[], int n) //Time complexity - O(n), Space complexity - O(n)
{
	vi v;
	stack<int>s;

	for (int i = n - 1; i >= 0; i--)
	{
		if (s.size() == 0)	v.push_back(-1);
		else if (s.top() > arr[i])	v.push_back(s.top());
		else //if (s.top() <= arr[i])
		{
			while (s.size() > 0 && s.top() <= arr[i])	s.pop();
			if (s.size() == 0)	v.push_back(-1);
			else v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	for (auto ele : v)	cout << ele << " ";
}

void nge(int arr[], int n) //Same as above but with less code
{
	vi nge(n);
	stack<int>s;

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() and s.top() <= arr[i])	s.pop();

		if (s.empty())	nge[i] = -1;
		else nge[i] = s.top();

		s.push(arr[i]);

	}

	for (int x : nge)	cout << x << " ";
}

void nge_circular(int arr[], int n) //Just run loop from 2*n-1 and do i%n instead of i
{
	vi nge(n);
	stack<int>s;

	for (int i = 2 * n - 1; i >= 0; i--)
	{
		while (!s.empty() and s.top() <= arr[i % n])	s.pop();

		if (s.empty())	nge[i % n] = -1;
		else nge[i % n] = s.top();

		s.push(arr[i % n]);

	}

	for (int x : nge)	cout << x << " ";
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	brute_force(arr, n);
	cout << endl;
	optimised(arr, n);
	cout << endl;
	nge(arr, n);
	return 0;
}