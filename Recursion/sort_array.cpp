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

void insert(vector<int>&v, int ele)
{
	if (v.size() == 0 || v[v.size() - 1] <= ele)
	{
		v.push_back(ele);
		return;
	}
	int val = v[v.size() - 1];
	v.pop_back();
	insert(v, ele);
	v.push_back(val);
}

void sort(vector<int>&v)
{
	if (v.size() == 1) return;
	int val = v[v.size() - 1];
	v.pop_back();
	sort(v);
	insert(v, val);
}

int main()
{
	starter();
	int n, i, ele;
	cin >> n;
	vector<int> v;
	for (i = 0; i < n; i++)
	{
		cin >> ele;
		v.push_back(ele);
	}
	sort(v);
	for (i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}