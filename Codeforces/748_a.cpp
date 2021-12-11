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
		int a, b, c;
		cin >> a >> b >> c;

		int max_votes = max({a, b, c});

		if (a == b && a == c)	cout << 1 << " " << 1 << " " << 1 << endl;

		else
		{
			if (a > b && a > c)
			{
				cout << 0 << " " << a - b + 1 << " " << a - c + 1 << endl;

			}

			else if (b > a && b > c)
			{
				cout << b - a + 1 << " " << 0 << " " << b - c + 1 << endl;

			}

			else if (c > a && c > b)
			{
				cout << c - a + 1 << " " << c - b + 1 << " " << 0 << endl;

			}
			// 2 max are equal
			else
			{
				if (a == b)
				{
					cout << 1 << " " << 1 << " " << b - c + 1 << endl;
				}
				else if (a == c)
				{
					cout << 1 << " " << a - b + 1 << " " << 1 << endl;
				}

				else cout << b - a + 1 << " " << 1 << " " << 1 << endl;
			}
		}
	}

	return 0;
}