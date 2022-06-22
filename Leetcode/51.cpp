//Time complexity - O(n^n)
//Space complexity - O(n^2)
class Solution {
public:

	bool isSafe(vector<string>&temp, int row, int col, int n)
	{
		int i, j;

		for (int k = 0; k < n; k++)
		{
			if (temp[k][col] == 'Q')	return false;
		}

		/* Check upper diagonal on left side */
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if (temp[i][j] == 'Q')	return false;

		/* Check lower diagonal on left side */
		for (i = row, j = col; i >= 0 && j < n; i--, j++)
			if (temp[i][j] == 'Q')	return false;

		return true;
	}

	void help(int i, int n, vector<string>&temp, vector<vector<string>>&op)
	{
		if (i == n)
		{
			op.push_back(temp);
			return;
		}

		for (int j = 0; j < n; j++)
		{
			if (isSafe(temp, i, j, n))
			{
				temp[i][j] = 'Q';
				help(i + 1, n, temp, op);
				temp[i][j] = '.';
			}
		}

	}


	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>>op;
		string s;
		for (int i = 0; i < n; i++)	s += '.';
		vector<string>temp(n, s);
		help(0, n, temp, op);

		return op;
	}
};