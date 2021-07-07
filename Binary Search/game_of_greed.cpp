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

bool isPossible(int mid, vector<int>&arr, int k) //A friend can get atleast mid no of coins
{
	int coins = 0;
	int friends = 0;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (coins + arr[i] >= mid)
		{
			friends++;
			coins = 0;
		}
		else coins += arr[i];
	}

	return friends >= k;
}

int getCoins(vector<int> &arr, int k) { //maximise the max coins a friend can get
	int n = arr.size();

	int start = INT_MAX, end = 0;
	for (int i = 0; i < n; i++)
	{
		start = min(start, arr[i]);
		end += arr[i];
	}
	int ans = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (isPossible(mid, arr, k))
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return ans;

}

int main()
{
	starter();
	int n, k;
	cin >> n >> k;
	vi coins(n);
	cin >> coins;
	cout << getCoins(coins, k);
	return 0;
}