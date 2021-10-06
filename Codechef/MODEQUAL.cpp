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

		vi A(n);

		int freq_min = 0;
		int min_ele = INT_MAX;

		for (int i = 0; i < n; i++)
		{
			cin >> A[i];

			if (A[i] < min_ele)
			{
				min_ele = A[i];
				freq_min = 1;
			}

			else if (A[i] == min_ele)
			{
				freq_min++;
			}

		}

		bool all = false;

		for (int i = 0; i < n; i++)
		{
			if (A[i] != min_ele)
			{
				if ((A[i] + 1) / 2 - 1 < min_ele)
				{
					all = true;
					break;
				}
			}
		}

		if (all)	cout << n << endl;
		else	cout << n - freq_min << endl;
	}

	return 0;
}