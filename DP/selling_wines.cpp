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

/*
Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sale the first or the last wine in the row. However, the price of wines increases over time.
Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi.
For each year, your task is to print “beg” or “end” denoting whether first or last wine should be sold.
Also, calculate the maximum profit from all the wines.
*/

//Recursion
//Time complexity - O(2^n)
int sellingWines(vi &wines, int i, int j, int year)
{

	if (i > j)	return 0;

	int pick_left = (wines[i] * year) + sellingWines(wines, i + 1, j, year + 1);
	int pick_right = (wines[j] * year) + sellingWines(wines, i, j - 1, year + 1);

	return max(pick_left, pick_right);
}

//Top Down DP
//Time complexity - O(n^2)
int sellingWinesTD(vi &wines, int i, int j, int year, vvi &dp)
{
	if (i > j)	return 0;

	if (dp[i][j] != -1)	return dp[i][j];

	int pick_left = (wines[i] * year) + sellingWinesTD(wines, i + 1, j, year + 1, dp);
	int pick_right = (wines[j] * year) + sellingWinesTD(wines, i, j - 1, year + 1, dp);

	return dp[i][j] = max(pick_left, pick_right);
}


//Diagonal Table Filling
//Bottom Up DP
//Time complexity - O(n^2)
int sellingWinesBU(vi &wines)
{
	int n = wines.size();
	vvi dp(n, vi(n, 0)); //dp[i][j] represents max profit you can get by selling wines from i to j and you've sold all other wines
	/*
	Filling in diagonal fashion

	dp[i][j-1] <----dp[i][j]
						|
						|
						V
					dp[i+1][j]

	We need element to the left and element to the down, therefore filling rows bottom to top and columns left to right
	*/
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				dp[i][j] = n * wines[i];
			}

			else if (i < j)
			{
				int year = n - (j - i);
				int pick_left = (year * wines[i]) + dp[i + 1][j];
				int pick_right = (year * wines[j]) + dp[i][j - 1];
				dp[i][j] = max(pick_left, pick_right);
			}
		}
	}


	//Printing beg or end i.e. moves
	string moves;
	int i = 0, j = n - 1;

	while (i < n and j >= 0)
	{
		int year = n - (j - i);

		if (dp[i + 1][j] == 0 and dp[i][j - 1] == 0)
		{
			moves += "beg ";
			break;
		}

		if (dp[i][j] == year * wines[i] + dp[i + 1][j])
		{
			moves += "beg ";
			i++;
		}

		else
		{
			moves += "end ";
			j--;
		}
	}

	cout << moves << ", and that maximum profit is ";

	return dp[0][n - 1];
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi wines(n);
	cin >> wines;

	vvi dp(n, vi(n, -1));

	cout << sellingWines(wines, 0, n - 1, 1) << " " << sellingWinesTD(wines, 0, n - 1, 1, dp) << endl;
	cout << "For maximum profit sell wines in this order -> " << sellingWinesBU(wines);

	return 0;
}