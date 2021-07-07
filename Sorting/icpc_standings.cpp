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

bool compare(pair<string, int>a, pair<string, int>b)
{
	return a.second < b.second;
}

/*int badness(vector<pair<string, int>> &teams) //O(nlogn)
{
	sort(teams.begin(), teams.end(), compare);
	int ans = 0;
	int last_rank = 1;
	for (auto p : teams)
	{
		if (p.second != last_rank)
		{
			ans += abs(last_rank - p.second);
		}
		last_rank++;
	}
	return ans;
}*/

int badness(vector<pair<string, int>> &teams) //O(n)
{
	int n = teams.size();
	vi ranks(n + 1, -1);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ranks[teams[i].second] == -1) //rank not alloted
		{
			ranks[teams[i].second] = 1;	//allote the rank
		}

		else
		{

		}
	}
	return ans;
}

int main()
{
	starter();
	int n;
	cin >> n;
	vector<pair<string, int>>teams(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		int x;
		cin >> s >> x;
		teams[i] = {s, x};
	}

	cout << badness(teams);
	return 0;
}