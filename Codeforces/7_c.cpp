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

int extended_euclid(int a, int b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;

	int ans = extended_euclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * 1LL * (a / b);

	return ans;
}

int main()
{
	starter();

	int a, b, c;
	cin >> a >> b >> c;

	c = -c;

	ll x, y;

	int g = extended_euclid(a, b, x, y);

	if (c % g)	cout << -1;
	else
	{
		x = x * 1LL * (c / g);
		y = y * 1LL * (c / g);

		cout << x << " " << y;
	}

	return 0;
}