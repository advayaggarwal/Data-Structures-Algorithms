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

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
           vector<vector<int>> &vis, int di[], int dj[])
{
	if (i == n - 1 && j == n - 1) {
		ans.push_back(move);
		return;
	}
	string dir = "DLRU";
	for (int ind = 0; ind < 4; ind++) {
		int nexti = i + di[ind];
		int nextj = j + dj[ind];
		if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
			vis[i][j] = 1;
			solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
			vis[i][j] = 0;
		}
	}
}

vector<string> findPath(vector<vector<int>> &m, int n) {
	vector<string> ans;
	vector<vector<int>> vis(n, vector<int> (n, 0));

	//We can move in all 4 directions D L R U
	int di[] = { +1, 0, 0, -1};
	int dj[] = {0, -1, 1, 0};

	if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
	return ans;
}

int main()
{
	starter();
	int n;
	cin >> n;

	vector<vi>grid(n, vi(n));
	cin >> grid;

	vector<string>ans = findPath(grid, n);

	cout << ans;

	return 0;
}