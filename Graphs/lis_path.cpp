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

void dfs(int i, int j, int m, int n, vvi &matrix, vector<vector<bool>> &visited, vvi &dp, int dx[], int dy[])
{
	visited[i][j] = true;
	int count = 0;

	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if ((x >= 0) and (y >= 0) and (x < m) and (y < n) and (matrix[x][y] > matrix[i][j]))
		{
			if (!visited[x][y])
			{
				dfs(x, y, m, n, matrix, visited, dp, dx, dy);
				count = max(count, 1 + dp[x][y]);
			}

			else
			{
				count = max(count, 1 + dp[x][y]);
			}
		}
	}

	dp[i][j] = count;
}

int longestPathSequence(vvi &matrix)
{
	int m = matrix.size(), n = matrix[0].size();

	vector<vector<bool>>visited(m + 1, vector<bool>(n + 1, false));

	int dx[] = { -1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	int ans = 0;
	vvi dp(m + 1, vi(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(i, j, m, n, matrix, visited, dp, dx, dy);
			ans = max(ans, dp[i][j]);
		}
	}

	return ans + 1;
}

int main()
{
	starter();

	int m, n;
	cin >> m >> n;

	vvi matrix(m, vi(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)	cin >> matrix[i][j];
	}

	cout << longestPathSequence(matrix);

	return 0;
}