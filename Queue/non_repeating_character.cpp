/*
	AUTHOR:			ADVAY AGGARWAL
*/

/*

==== You are given a running stream of characters, output the first non-repeating character in the string formed so
==== far after every character you get in input.
==== Output 0 if such a character doesn't exist.

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

//Using hashmap and queue, queue tells which element come first and hashmap gives the frequency of that element

vector<char>firstNonRepeatingChar(string s)
{
	vector<char>res;
	queue<char>q;
	vi freq(26, 0);

	for (char ch : s)
	{
		freq[ch - 'a']++;

		q.push(ch);

		while (!q.empty() and freq[q.front() - 'a'] > 1) q.pop(); //pop until we get ele which has freq 1 or q is empty

		if (q.empty())	res.push_back('0');	//there is no element which has frequency 1

		else	res.push_back(q.front());

	}

	return res;
}

int main()
{
	starter();

	string s;
	cin >> s;

	vector<char>res = firstNonRepeatingChar(s);

	cout << res;
	return 0;
}