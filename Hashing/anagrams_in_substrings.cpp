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
1. Generate all substrings
2. Generate their hash
3. Hash the 'hashed' values to club all anagrams in a single bucket, to get their frequency count
4. From the frequency count, we can easily count the pairs
*/

//Time complexity - O(N^2*logN)
int anagramSubstrings(string s)
{
	map<vi, int>m;

	int n = s.size();
	for (int i = 0; i < n; i++) //O(N^2 * logN)
	{
		vi freq(26, 0);

		for (int j = i; j < n; j++)
		{
			freq[s[j] - 'a']++;
			m[freq]++; //O(logN)
		}
	}

	int ans = 0;

	for (auto p : m) //O(N^2), if all substrings are different
	{
		ans += (p.second * (p.second - 1)) / 2;
	}

	return ans;
}

int main()
{
	starter();

	string s;
	cin >> s;

	cout << anagramSubstrings(s);

	return 0;
}