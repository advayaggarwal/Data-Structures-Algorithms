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

void insert(stack<int>&s, int temp)
{
	if (s.size() == 0)
	{
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s, temp);
	s.push(val);
}

void reverse_stack(stack<int>&s)
{
	if (s.size() == 1) return;
	int temp = s.top();
	s.pop();
	reverse_stack(s);
	insert(s, temp);
}

int main()
{
	starter();
	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		s.push(ele);
	}
	reverse_stack(s);
	for (int i = 0; i < n; i++)
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}