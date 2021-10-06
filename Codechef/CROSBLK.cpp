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

		int ans = 0;

		int i = n - 1;

		while (i > 0)
		{
			ans++;

			int j = i;
			bool done = false;
			while (j >= 0 && a[j] <= a[i])
			{
				j--;

				if (j == -1 && a[j + 1] == a[i])
				{
					done = true;
					break;
				}
			}

			if (done)
			{
				i = 0;
				break;
			}

			i = j;
		}

		if (i < 0)	ans = -1;

		cout << ans << endl;

	}

	return 0;
}