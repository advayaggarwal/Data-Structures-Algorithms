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

void permutations(string &ip, int index, int n, vector<string>&res) //O(n*n!)
{
	if (index == n)
	{
		res.push_back(ip);
		return;
	}

	for (int i = index; i < n; i++)
	{
		swap(ip[i], ip[index]);
		permutations(ip, index + 1, n, res);
		swap(ip[i], ip[index]);//Backtracking, C++ strings are pass by value not pass by reference, so no need of backtracking
	}
}

int main()
{
	starter();
	string ip;
	cin >> ip;
	vector<string>res;
	permutations(ip, 0, ip.size(), res);
	for (string s : res)	cout << s << endl;
	return 0;
}