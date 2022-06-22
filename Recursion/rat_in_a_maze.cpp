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

bool findPath(vector<vi> &grid, vector<vi> &sol, int i, int j, int n)
{
	if (i == n - 1 && j == n - 1)
	{
		sol[i][j] = 1;
		return true;
	}

	if (i == n or j == n)	return false;


	if (grid[i][j] == 1)
	{
		sol[i][j] = 1;

		if (findPath(grid, sol, i + 1, j, n) or findPath(grid, sol, i, j + 1, n))
		{
			return true;
		}

		else sol[i][j] = 0;
	}

	return false;
}


int main()
{
	starter();
	int n;
	cin >> n;

	vector<vi>grid(n, vi(n));
	cin >> grid;

	vector<vi>sol(n, vi(n, 0));

	if (!findPath(grid, sol, 0 , 0, n)) cout << "Solution doesn't exist" << endl;

	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)	cout << sol[i][j] << " ";
			cout << endl;

		}
	}

	return 0;
}