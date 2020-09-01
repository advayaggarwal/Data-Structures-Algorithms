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

int solve(vector<int> &v, int k, int index)
{
	if (v.size() == 1)	return v[0];
	index = (index + k) % v.size();
	v.erase(v.begin() + index);
	return solve(v, k, index);
}

int main()
{
	starter();
	int n, k;
	cin >> n >> k;
	vector<int> v;
	k--;
	for (int i = 1; i <= n; i++)	v.push_back(i);
	int index = 0;
	cout << solve(v, k, index);
	return 0;
}