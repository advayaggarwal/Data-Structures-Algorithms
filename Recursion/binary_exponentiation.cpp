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

//Recursive
//Time complexity - O(logb)
//Space complexity - O(logb)
ll powerModulo(int a, int b)
{
	if (b == 0)    return 1;

	ll temp = powerModulo(a, b / 2);
	ll res = (temp * temp) % mod;

	if (b & 1) res = (res * a) % mod;

	return res;
}

//Iterative
//Time complexity - O(logb)
//Space complexity - O(1)
ll binaryExponentiation(int a, int b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)	res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

int main()
{
	starter();
	int a, b;
	cin >> a >> b;
	cout << powerModulo(a, b) << endl;
	cout << binaryExponentiation(a, b);
	return 0;
}
