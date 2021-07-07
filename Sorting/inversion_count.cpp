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


int merge(vector<int>&arr, int lo, int mid, int hi)
{
	vector<int>temp;
	int cnt = 0;
	int i = lo, j = mid + 1;

	while (i <= mid && j <= hi)
	{
		if (arr[i] < arr[j])	temp.push_back(arr[i++]);

		else
		{
			cnt += (mid - i + 1);
			temp.push_back(arr[j++]);
		}
	}

	while (i <= mid)	temp.push_back(arr[i++]);
	while (j <= hi)	temp.push_back(arr[j++]);


	int k = 0;
	for (int i = lo; i <= hi; i++)	arr[i] = temp[k++];
	return cnt;
}


int inversionCount(vector<int>&arr, int lo, int hi)
{
	if (lo >= hi)	return 0;

	int mid = lo + (hi - lo) / 2;
	int c1 = inversionCount(arr, lo, mid);
	int c2 = inversionCount(arr, mid + 1, hi);
	int ci = merge(arr, lo, mid, hi);
	return c1 + c2 + ci;
}


int main()
{
	starter();
	int n;
	cin >> n;
	vi arr(n);
	cin >> arr;
	cout << inversionCount(arr, 0, n - 1);
	return 0;
}