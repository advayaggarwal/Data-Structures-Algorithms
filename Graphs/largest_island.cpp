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

void dfs(int i, int j, int m, int n, vvi &grid, vector<vector<bool>>&visited, int &area, int dx[], int dy[])
{
	visited[i][j] = true;
	area++;

	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k], y = j + dy[k];

		if (x >= 0 and y >= 0 and x < m and y < n and !visited[x][y] and grid[x][y] == 1)
		{
			dfs(x, y, m, n, grid, visited, area, dx, dy);
		}
	}
}

void bfs(int i, int j, int m, int n, vvi &grid, vector<vector<bool>>&visited, int &area, int dx[], int dy[])
{
	visited[i][j] = true;
	queue<pii>q;
	q.push({i, j});

	while (!q.empty())
	{
		area++;
		int ni = q.front().first;
		int nj = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int x = ni + dx[k], y = nj + dy[k];

			if (x >= 0 and y >= 0 and x < m and y < n and !visited[x][y] and grid[x][y] == 1)
			{
				q.push({x, y});
				visited[x][y] = true;
			}
		}
	}

}

//Time complexity - O(m*n)
//Space complexity - O(m*n)
int largest_island(vvi &grid)
{
	int m = grid.size(), n = grid[0].size();

	vector<vector<bool>> visited(m, vector<bool>(n, false));

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int largest_area = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] and grid[i][j] == 1)
			{
				int area = 0;
				dfs(i, j, m, n, grid, visited, area, dx, dy); //or bfs(i, j, m, n, grid, visited, area, dx, dy);
				largest_area = max(largest_area, area);
			}
		}
	}

	return largest_area;
}

int main()
{
	starter();

	int m, n;
	cin >> m >> n;

	vvi grid(m, vi(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)	cin >> grid[i][j];
	}

	cout << largest_island(grid);
	return 0;
}