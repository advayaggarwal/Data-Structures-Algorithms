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
		vector<pii>pt(n);

		for (int i = 0; i < n; i++)	cin >> pt[i].first;
		for (int i = 0; i < n; i++)	cin >> pt[i].second;

		int res = INT_MAX;

		for (int i = 0; i < n; i++)
		{
			int x1 = x[i], y1 = y[i];
			int ans = 0;
			//Making all other points equal to (x1,y1)
			for (int j = 0; j < n; j++)
			{
				if (i == j)	continue;
				int x2 = x[j], y2 = y[j];

				if (x1 == x2 and y1 == y2)	ans += 0;
				else if (x1 == x2)	ans += 1;
				else if (y1 == y2)	ans += 1;
				else if (x1 - x2 == y1 - y2)	ans += 1;
				else if (x1 + y1 == x2 + y2)	ans += 1;
				else ans += 2;
			}

			res = min(res, ans);
		}

		cout << res << endl;
	}

	return 0;
}