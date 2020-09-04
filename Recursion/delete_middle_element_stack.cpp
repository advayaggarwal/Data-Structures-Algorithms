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

void delete_middle(stack<int>&s, int k)
{
	if (k == 0)
	{
		s.pop();
		return;
	}
	int val = s.top();
	s.pop();
	delete_middle(s, k - 1);
	s.push(val);
}

int main()
{
	starter();
	int n;
	cin >> n;
	stack<int>s;
	for (int i = 0; i < n; i++)
	{
		int ele;
		cin >> ele;
		s.push(ele);
	}
	delete_middle(s, n / 2);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}