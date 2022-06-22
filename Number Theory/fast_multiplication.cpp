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

//Given a, b and c. Find (a*b)%c, where a, b, c <= 1e15

ll multiply(ll a, ll b, ll c)
{
	ll res = 0;
	while (b)
	{
		if (b & 1)
		{
			res += a;
			res %= c;
		}

		a += a;
		a %= c;
		b /= 2;
	}

	return res;
}

int main()
{
	starter();

	ll a, b, c;
	cin >> a >> b >> c;

	cout << multiply(a, b, c);

	return 0;
}