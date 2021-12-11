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

int binary_exponentiation(int no, int p)
{
	int result = 1;

	while (p)
	{
		if (p & 1)
		{
			result = result * no;
		}

		no = no * no;
		p /= 2;
	}

	return result;
}

int main()
{
	starter();
	test_cases(t)
	{
		int x;
		cin >> x;

		int temp = x;
		int bit_count = 0;
		while (temp)
		{
			bit_count++;
			temp >>= 1;
		}

		if (x == binary_exponentiation(2, bit_count) - 1)	cout << x + 1 << endl;

		else cout << binary_exponentiation(2, bit_count - 1) << endl;
	}

	return 0;
}