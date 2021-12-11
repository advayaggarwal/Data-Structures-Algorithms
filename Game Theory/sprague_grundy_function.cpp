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

int mex(unordered_set<int>&s)
{
	int Mex = 0;

	while (s.find(Mex) != s.end())	Mex++;

	return Mex;
}

//There is a pile of n stones and in one turn a player can take at max 3(K) stones from a pile.
//This is a normal rule game. Determine the winner if Alice starts first

//Time complexity - O(N*K)
int calculateGrundy(int n, vi &grundy)
{
	if (n == 0)	return 0;
	if (grundy[n] != -1)	return grundy[n];

	unordered_set<int>s;

	for (int i = n - 1; i >= n - 3 && i >= 0; i--) //O(3)
	{
		s.insert(calculateGrundy(i, grundy));
	}

	return grundy[n] = mex(s);
}

int main()
{
	starter();

	int n;
	cin >> n;

	vector<int>grundy(n + 1, -1);

	int ans = calculateGrundy(n, grundy);

	if (ans != 0)	cout << "Alice will win";
	else cout << "Bob will win";
	return 0;
}