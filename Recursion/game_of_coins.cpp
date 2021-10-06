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

int gameOfCoins(vi &c, int i, int j)
{

	if (i == j)	return c[i];

	if (i > j)	return 0;

	//taking min because both the players are playing optimally
	int option1 = c[i] + min(gameOfCoins(c, i + 1, j - 1), gameOfCoins(c, i + 2, j)); //picking the leftmost coin

	int option2 = c[j] + min(gameOfCoins(c, i, j - 2), gameOfCoins(c, i + 1, j - 1)); //picking the rightmost coin

	return max(option1, option2);
}

int MaxValue(int n, vector<int> v)
{
	return gameOfCoins(v, 0, n - 1);
}

int main()
{
	starter();

	int n;
	cin >> n;
	vi c(n);
	cin >> c;

	cout << MaxValue(n, c);

	return 0;
}