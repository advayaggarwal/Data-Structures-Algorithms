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

bool isPalindrome(string &s, int i, int j)
{
	while (i < j)
	{
		if (s[i++] != s[j--])	return false;
	}

	return true;
}

//Time complexity - O(n*(2^n))
void partition(string &s, int index, int n, vector<string>&ans, vector<vector<string>>&res)
{
	if (index == n)
	{
		res.push_back(ans);
		return;
	}

	for (int i = index; i < n; i++)
	{
		if (isPalindrome(s, index, i)) //Everytime we are checking if s from index to i is palindrome or not
			//Many substrings are being checked again and again, Overlapping subproblems are there, Use DP
			//But complexity will remain O(n*(2^n)) as for each palindrome we still need O(n) time to generate
			//substring from index to i indices.
		{
			ans.push_back(s.substr(index, (i - index + 1)));
			partition(s, i + 1, n, ans, res);
			ans.pop_back();
		}
	}
}

int main()
{
	starter();

	string s;
	cin >> s;

	vector<vector<string>>res;
	vector<string>ans;

	partition(s, 0, s.size(), ans, res);

	for (auto v : res)
	{
		for (auto st : v)
		{
			cout << st << " ";
		}
		cout << endl;
	}

	return 0;
}