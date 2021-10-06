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
#define pii pair<int,int>
#define vvi vector<vi>

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

pair<bool, int> possible(int k, vector<pii> &cost, int S)
{
	ll price = 0;

	sort(cost.begin(), cost.end(), [&](const pii & a, const pii & b) {
		return (a.first + (k * a.second)) < (b.first + (k * b.second));
	});

	for (int i = 0; i < k; i++)
	{
		price += (cost[i].first + (k * 1LL * (cost[i].second)));

		if (S < price)	return {false, 0};
	}

	return {true, price};
}

int main()
{
	starter();
	int n, S;
	cin >> n >> S;

	vector<pii> cost(n);

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		cost[i] = {c, i + 1};
	}

	int items = 0;
	ll money = 0;
	int low = 1, high = n;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		pair<bool, int> ans = possible(mid, cost, S);

		if (ans.first == true)
		{
			items = mid;
			money = ans.second;
			low = mid + 1;
		}

		else high = mid - 1;
	}

	cout << items << " " << money;

	return 0;
}