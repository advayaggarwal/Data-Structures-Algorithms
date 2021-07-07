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

bool isSafe(vector<vi> &grid, int i, int j, int no, int n)
{
	//check for row and column
	for (int k = 0; k < n; k++)
	{
		if (grid[i][k] == no || grid[k][j] == no)	return false;
	}

	//check for subgrid
	int sqrt_n = sqrt(n);
	int sx = (i / sqrt_n) * sqrt_n; //x coordinate of starting point
	int sy = (j / sqrt_n) * sqrt_n; //y coordinate of starting point
	for (int x = sx; x < sx + sqrt_n; x++)
	{
		for (int y = sy; y < sy + sqrt_n; y++)
		{
			if (grid[x][y] == no)	return false;
		}
	}

	return true;
}

//Time complexity - O(n^(n*n)), considering all cells are to be filled

//1st approach
bool solve(vector<vector<int>>& board, int n)
{
	//simply traverse the board and search for an empty cell and try to fill nos 1-9, and again try to solve the board,
	//if not possible revert the changes, i.e. backtrack
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
			{
				for (int no = 1; no <= n; no++)
				{
					if (isSafe(board, i, j, no, n))
					{
						board[i][j] = no;
						if (solve(board, n))  return true;
						else board[i][j] = 0; //reverting the changes, making it unfilled
					}
				}
				return false; //tried all the possibilites, can't fill any no from 1-9,
				//so we have to change the previous filled cell
			}
		}
	}
	return true;
}

//2nd approach
bool solveSudoku(vector<vi> &grid, int i, int j, int n)
{
	//Base Case
	if (i == n) //completed the whole grid
	{
		//print the solution
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)	cout << grid[i][j] << " ";
			cout << endl;
		}
		return true;
	}

	//Recursive Case
	if (j == n)
	{
		return solveSudoku(grid, i + 1, 0, n);
	}

	//skip the prefilled cell
	if (grid[i][j] != 0)
	{
		return solveSudoku(grid, i, j + 1, n);
	}

	//cell to be filled
	//try out all possibilities
	for (int no = 1; no <= n; no++)
	{
		//check whether it is safe to place the number or not
		if (isSafe(grid, i, j, no, n))
		{
			grid[i][j] = no;
			bool solveSubproblem = solveSudoku(grid, i, j + 1, n);
			if (solveSubproblem == true)	return true;
		}
	}

	//if no option works, backtrack
	grid[i][j] = 0;
	return false;
}

int main()
{
	starter();
	int n;
	cin >> n;
	vector<vi> grid(n, vi(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)	cin >> grid[i][j];
	}

	if (!solveSudoku(grid, 0, 0, n))
	{
		cout << "No solution exists!" << endl;
	}

	return 0;
}