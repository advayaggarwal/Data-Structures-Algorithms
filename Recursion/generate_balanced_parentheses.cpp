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

void generateParentheses(string op, int n, int opening, int closing)
{
	//Base Case
	if (opening == n && closing == n)
	{
		cout << op << endl;
		return;
	}

	if (opening < n)	generateParentheses(op + '(', n, opening + 1, closing);

	if (closing < n && opening > closing)	generateParentheses(op + ')', n, opening, closing + 1);
}

int main()
{
	starter();
	int n;
	cin >> n;
	string op = "";
	generateParentheses(op, n, 0, 0); //initially count of opening and closing is 0
	return 0;
}