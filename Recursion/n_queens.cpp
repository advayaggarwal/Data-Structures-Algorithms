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


bool isSafe(vector<string>&temp, int row, int col, int n) //O(n)
{
	int i, j;

	// Check column col, no need to check below row i.e. UP
	for (int k = 0; k <= row; k++)
	{
		if (temp[k][col] == 'Q')	return false;
	}

	// Check upper diagonal on left side
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (temp[i][j] == 'Q')	return false;
	}

	// Check upper diagonal on right side
	for (i = row, j = col; i >= 0 && j < n; i--, j++)
	{
		if (temp[i][j] == 'Q')	return false;
	}

	return true;
}

void n_queens(int row, int n, vector<string>&temp, vector<vector<string>>&res)
{
	if (row == n)
	{
		res.push_back(temp);
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (isSafe(temp, row, col, n))
		{
			temp[row][col] = 'Q';
			n_queens(row + 1, n, temp, res);
			temp[row][col] = '.';
		}
	}
}

int main()
{
	starter();
	int n;
	cin >> n;
	vector<vector<string>>res;
	string s;
	for (int i = 0; i < n; i++)	s += '.';
	vector<string>temp(n, s);

	n_queens(0, n, temp, res);

	for (int i = 0; i < (int)res.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res[i][j] << endl;
		}
		cout << endl;
	}

	return 0;
}

/*

//Above code can be optimised by using hashing, we don't have to use isSafe(), it is taking O(n), we can use vectors to mark
//if the current column and upper diagonals are already filled.
//Watch striver's video for explanation

void n_queens(int row, int n, vector<string>&temp, vi &col_filled, vi &upper_left_diagonal_filled, vi &upper_right_diagonal_filled, vector<vector<string>>&res)
{
	if (row == n)
	{
		res.push_back(temp);
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (col_filled[col] == 0 && upper_right_diagonal_filled[row + col] == 0 && upper_left_diagonal_filled[n - 1 + col - row] == 0)
		{
			//marking as filled so that we don't have to call isSafe
			col_filled[col] = 1;
			upper_right_diagonal_filled[row + col] = 1;
			upper_left_diagonal_filled[n - 1 + col - row] = 1;
			temp[row][col] = 'Q';
			n_queens(row + 1, n, temp, col_filled, upper_left_diagonal_filled, upper_right_diagonal_filled, res);

			//backtracking
			col_filled[col] = 0;
			upper_right_diagonal_filled[row + col] = 0;
			upper_left_diagonal_filled[n - 1 + col - row] = 0;
			temp[row][col] = '.';
		}
	}
}

int main()
{
	starter();
	int n;
	cin >> n;
	vector<vector<string>>res;
	string s;
	for (int i = 0; i < n; i++)	s += '.';
	vector<string>temp(n, s);

	vi col_filled(n, 0), upper_left_diagonal_filled(2 * n - 1, 0), upper_right_diagonal_filled(2 * n - 1, 0);

	n_queens(0, n, temp, col_filled, upper_left_diagonal_filled, upper_right_diagonal_filled, res);

	for (int i = 0; i < (int)res.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res[i][j] << endl;
		}
		cout << endl;
	}

	return 0;
}
*/