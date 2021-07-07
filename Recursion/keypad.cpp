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

unordered_map<char, vector<char>> m;

void keypad(string s, int index, int n, string op)
{
	while (index < n && m.find(s[index]) == m.end())	index += 1; //for corner cases like 0 and 1

	if (index == n)
	{
		cout << op << endl;
		return;
	}

	for (char letter : m[s[index]])	keypad(s, index + 1, n, op + letter);
}

int main()
{
	starter();
	string s;
	cin >> s;
	string op;

	m['2'] = {'a', 'b', 'c'};
	m['3'] = {'d', 'e', 'f'};
	m['4'] = {'g', 'h', 'i'};
	m['5'] = {'j', 'k', 'l'};
	m['6'] = {'m', 'n', 'o'};
	m['7'] = {'p', 'q', 'r', 's'};
	m['8'] = {'t', 'u', 'v'};
	m['9'] = {'w', 'x', 'y', 'z'};

	keypad(s, 0, s.size(), op);
	return 0;
}