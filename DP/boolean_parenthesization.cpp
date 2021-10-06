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

//Time complexity - O(4^n)
int parenthesization(string &s, int i, int j, bool isTrue)
{
	if (i > j)	return 0; //no chars left

	if (i == j) //only 1 char is there
	{
		if (isTrue)	return s[i] == 'T';
		else return s[i] == 'F';
	}


	int ans = 0;
	//i and j will always point to T or F and k will always point to an operator
	for (int k = i + 1; k < j; k += 2) //k will point to the operator, and we've to do +2 so that it will again point to operator
	{
		int lt = parenthesization(s, i, k - 1, true); //Left True
		int lf = parenthesization(s, i, k - 1, false); //Left False
		int rt = parenthesization(s, k + 1, j, true); //Right True
		int rf = parenthesization(s, k + 1, j, false); //Right False

		if (s[k] == '&')
		{
			if (isTrue)	ans +=  lt * rt;

			else ans += lf * rt + lt * rf + lf * rf;
		}

		else if (s[k] == '|')
		{
			if (isTrue)	ans += lt * rf + lf * rt + lt * rt;

			else ans += lf * rf;
		}

		else
		{
			if (isTrue)	ans += lt * rf + lf * rt;

			else ans += lt * rt + lf * rf;
		}
	}
	return ans;
}

//Requires either 3d matrix or map as 2*(n^2) states are there i.e. 3 variables that are changing i, j and isTrue
// n*n*2
//Time complexity - O(n^3)
//Space complexity - O(n^2)
int parenthesizationTD(string &s, int i, int j, bool isTrue, unordered_map<string, int>&m)
{
	if (i > j)	return 0;

	if (i == j)
	{
		if (isTrue)	return s[i] == 'T';

		else return s[i] == 'F';
	}


	string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

	if (m.find(temp) != m.end())	return m[temp];

	int ans = 0;

	for (int k = i + 1; k < j; k += 2)
	{
		int lt = parenthesizationTD(s, i, k - 1, true, m); //Left True
		int lf = parenthesizationTD(s, i, k - 1, false, m); //Left False
		int rt = parenthesizationTD(s, k + 1, j, true, m); //Right True
		int rf = parenthesizationTD(s, k + 1, j, false, m); //Right False

		if (s[k] == '&')
		{
			if (isTrue)	ans +=  lt * rt;

			else ans += lf * rt + lt * rf + lf * rf;
		}

		else if (s[k] == '|')
		{
			if (isTrue)	ans += lt * rf + lf * rt + lt * rt;

			else ans += lf * rf;
		}

		else
		{
			if (isTrue)	ans += lt * rf + lf * rt;

			else ans += lt * rt + lf * rf;
		}
	}

	return m[temp] = ans;
}

int main()
{
	starter();

	string s;
	cin >> s;

	int n = s.size();
	unordered_map<string, int>m; //using map as there are 3 variables that are changing, cannot be done in 2d matrix

	cout << parenthesization(s, 0, n - 1, true) << " " << parenthesizationTD(s, 0, n - 1, true, m);

	return 0;
}