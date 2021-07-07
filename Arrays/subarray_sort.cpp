/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
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
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}


bool outOfOrder(vector<int>&arr, int i)
{
	if (i == 0)	return arr[0] > arr[1];

	else if (i == (int)arr.size() - 1)	return arr[i] < arr[i - 1];

	return (arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1]);
}

pair<int, int> subarraySort(vector<int>&arr)
{
	//Find smallest and largest elements which are out of the order

	int smallest = INT_MAX;
	int largest = INT_MIN;

	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (outOfOrder(arr, i))
		{
			smallest = min(smallest, arr[i]);
			largest = max(largest, arr[i]);
		}
	}

	if (smallest == INT_MAX || largest == INT_MIN)	return { -1, -1};

	int start = 0, end = arr.size() - 1;

	while (arr[start] <= smallest)	start++;
	while (arr[end] >= largest)	end--;

	return {start, end};
}

int main()
{
	starter();
	int n;
	cin >> n;
	vi arr(n);
	cin >> arr;
	pair<int, int>p = subarraySort(arr);
	cout << p.first << " " << p.second;
	return 0;
}