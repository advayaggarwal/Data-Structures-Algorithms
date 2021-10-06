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

int main()
{
	starter();
	test_cases(t)
	{
		int n;
		cin >> n;

		vi a(n);
		cin >> a;

		int odd_index = (n + 2 - 1) / 2;
		int even_index = n - odd_index;

		int even = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)	even++;
		}

		int odd = n - even;

		int res = 0;

		if (odd == even_index && even == odd_index)	res = n;

		else
		{
			res = min(odd, even_index) + min(even, odd_index);
		}

		cout << res << endl;
	}

	return 0;
}