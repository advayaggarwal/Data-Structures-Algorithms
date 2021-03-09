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

vi nsl(vi arr, int n) //Nearest smaller to left
{
	stack<pair<int, int>>s; //{element, index}
	vi v;
	for (int i = 0; i < n; i++)
	{
		if (s.size() == 0)	v.push_back(-1);
		else if (s.top().first < arr[i])	v.push_back(s.top().second);
		else
		{
			while (s.size() != 0 && s.top().first >= arr[i])	s.pop();
			if (s.size() == 0)	v.push_back(-1);
			else v.push_back(s.top().second);
		}
		s.push({arr[i], i});
	}
	return v;
}

vi nsr(vi arr, int n) //Nearest smaller to right
{
	stack<pair<int, int>>s; //{element, index}
	vi v;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s.size() == 0)	v.push_back(n);
		else if (s.top().first < arr[i])	v.push_back(s.top().second);
		else
		{
			while (s.size() != 0 && s.top().first >= arr[i])	s.pop();
			if (s.size() == 0)	v.push_back(n);
			else v.push_back(s.top().second);
		}
		s.push({arr[i], i});
	}
	reverse(v.begin(), v.end());
	return v;
}


int mah(vi arr)
{
	vi right_index = nsr(arr, arr.size());
	vi left_index = nsl(arr, arr.size());
	int max = INT_MIN;
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (arr[i] * (right_index[i] - left_index[i] - 1) > max)	max = arr[i] * (right_index[i] - left_index[i] - 1);
	}

	return max;
}

int main()
{
	starter();
	int n, m;
	cin >> n >> m;
	vector<vi> v(n, vi(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	int mx = mah(v[0]);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 1)	v[i][j] += v[i - 1][j];
		}

		mx = max(mx, mah(v[i]));
	}

	cout << mx;

	return 0;
}