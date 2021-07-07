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
	test_cases(t)
	{
		int n, m;
		cin >> n >> m;
		vi A(n);
		vi B(m);
		cin >> A >> B;
		for (int i = 0; i < m; i++)
		{
			B[i]--;
		}
		vi li(n, -1), ri(n, n);
		int l1 = -1, r2 = n;

		for (int i = 0; i < n; i++)
		{
			if (A[i] == 1)	l1 = i;
			li[i] = l1;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (A[i] == 2)	r2 = i;
			ri[i] = r2;
		}
		//cout << li << endl << ri << endl;

		for (int i = 0; i < m; i++)
		{
			if (B[i] == 0)	cout << 0 << " ";
			else
			{
				if (li[B[i]] == -1 && ri[B[i]] == n)	cout << -1 << " ";
				else if (li[B[i]] == -1)	cout << ri[B[i]] - B[i] << " ";
				else if (ri[B[i]] == n)	cout << B[i] - li[B[i]] << " ";
				else	cout << min(B[i] - li[B[i]], ri[B[i]] - B[i]) << " ";
			}
		}
		cout << endl;
	}
	return 0;
}