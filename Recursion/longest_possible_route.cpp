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

bool findPath(int i, int j, vector<vi>&grid, int m, int n, vector<vi>&visited, int &ans, int steps)
{
	if (i == m - 1 and j == n - 1)
	{
		ans = max(ans, steps);
		return true;
	}

	if (i == m or j == n or i < 0 or j < 0)	return false;

	if (grid[i][j] == 1 && !visited[i][j])
	{
		visited[i][j] = 1;

		bool ans1 = findPath(i + 1, j, grid, m, n, visited, ans, steps + 1);
		bool ans2 = findPath(i, j + 1, grid, m, n, visited, ans, steps + 1);
		bool ans3 = findPath(i - 1, j, grid, m, n, visited, ans, steps + 1);
		bool ans4 = findPath(i, j - 1, grid, m, n, visited, ans, steps + 1);

		visited[i][j] = 0;

		if (ans1 or ans2 or ans3 or ans4)	return true;
	}

	return false;
}

int findLongestPath(int m, int n, vector<vector<int>> v)
{
	int ans = 0;

	vector<vi>visited(m, vi(n, 0));

	findPath(0, 0, v, m, n, visited, ans, 0);

	return ans;
}


int main()
{
	starter();

	int m, n;
	cin >> m >> n;

	vector<vi>grid(m, vi(n));
	cin >> grid;

	cout << findLongestPath(m, n, grid);
	return 0;
}