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

		set<int>a;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.insert(x);
		}

		vi A;
		for (int no : a)
		{
			A.push_back(no);
		}

		if (A.size() == 1)	cout << -1 << endl;

		else if (A.size() == 2) cout << A[1] - A[0] << endl;

		else
		{
			int k = 1;

			int target = A[0];
			int gcd = A[1] - target;

			for (int j = 2; j < A.size(); j++)
			{
				gcd = __gcd(gcd, A[j] - target);
			}

			k = max(k, gcd);
			cout << k << endl;
		}
	}

	return 0;
}