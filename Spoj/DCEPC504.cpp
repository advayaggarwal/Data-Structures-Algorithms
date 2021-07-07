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

string solve(string root, ll n, ll k)
{
	if (n == 1)	return root;

	ll total_children = pow(2, n - 1);

	if (k <= total_children / 2)
	{
		return solve(root, n - 1, k);
	}

	else
	{
		string new_root = root == "Male" ? "Female" : "Male";
		return solve(new_root, n - 1, k - (total_children / 2));
	}
}

int main()
{
	starter();
	test_cases(t)
	{
		ll n, k;
		cin >> n >> k;
		cout << solve("Male", n, k) << endl;
	}
	return 0;
}