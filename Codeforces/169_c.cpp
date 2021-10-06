/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	starter();
	int n, q;
	cin >> n >> q;
	vi a(n + 1);
	for (int i = 1; i <= n; i++)	cin >> a[i];

	vector<pair<int, int>> freq(n + 2); //{freq,index}

	for (int i = 1; i <= n; i++)	freq[i].second = i;

	ll sum = 0;

	vector<pair<int, int>>queries;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		queries.push_back({l, r});
		freq[l].first++;
		freq[r + 1].first--;
	}

	for (int i = 1; i <= n + 1; i++)	freq[i].first += freq[i - 1].first;

	sort(freq.begin(), freq.end(), greater<pair<int, int>>());

	vi A(n + 1);
	sort(a.begin(), a.end(), greater<int>());

	for (int i = 0; i < n; i++)
	{
		A[freq[i].second] = a[i];
	}

	vector<ll> pre(n + 2);
	for (int i = 1; i <= n; i++)	pre[i] = pre[i - 1] + A[i];


	for (int i = 0; i < queries.size(); i++)
	{
		sum +=  (pre[queries[i].second] - pre[queries[i].first - 1]);
	}

	cout << sum;
	return 0;
}