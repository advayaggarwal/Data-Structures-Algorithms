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

//Recursion
//Time complexity - O(4^n)
bool scramble(string s1, string s2)
{
	if (s1 == s2)	return true;

	if (s1.size() <= 1)	return false;

	int n = s1.size();

	for (int i = 1; i < n; i++)
	{
		bool op1 = (scramble(s1.substr(0, i), s2.substr(0, i)) && scramble(s1.substr(i, n - i), s2.substr(i, n - i)));
		if (op1) return true;
		bool op2 = (scramble(s1.substr(0, i), s2.substr(n - i, i)) && scramble(s1.substr(i, n - i), s2.substr(0, n - i)));
		if (op2)	return true;
	}

	return false;
}

//Top Down DP
//Time complexity - O(n^3)
bool scrambleTD(string s1, string s2, unordered_map<string, bool>&m)
{
	if (s1 == s2)	return true;
	if (s1.size() <= 1)	return false;

	string key = s1 + " " + s2;

	if (m.find(key) != m.end())	return m[key];

	int n = s1.size();
	for (int i = 1; i < n; i++)
	{
		bool op1 = scrambleTD(s1.substr(0, i), s2.substr(0, i), m) && scrambleTD(s1.substr(i, n - i), s2.substr(i, n - i), m);
		if (op1) return m[key] = true;

		bool op2 = scrambleTD(s1.substr(0, i), s2.substr(n - i, i), m) && scrambleTD(s1.substr(i, n - i), s2.substr(0, n - i), m);
		if (op2) return m[key] = op2;
	}

	return m[key] = false;
}

int main()
{
	starter();

	string s1, s2;
	cin >> s1 >> s2;

	unordered_map<string, bool>m;
	cout << scramble(s1, s2) << " " << scrambleTD(s1, s2, m);

	return 0;
}