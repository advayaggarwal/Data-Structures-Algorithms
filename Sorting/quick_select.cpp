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

int partition(vi &arr, int lo, int hi)
{
	int pivot = arr[hi];
	int i = lo - 1;

	for (int j = lo; j <= hi; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	return i;
}

int quickSelect(vi &arr, int lo, int hi, int k)
{
	if (lo <= hi) {

		int pi = partition(arr, lo, hi);
		if (pi == k)	return arr[pi];
		else if (pi < k)	return quickSelect(arr, pi + 1, hi, k);
		else return quickSelect(arr, lo, pi - 1, k);
	}

	else return -1; //if k is out of bound

}

int main()
{
	starter();
	int n, k;
	cin >> n;
	vi arr(n);
	cin >> arr;
	test_cases(t)
	{
		cin >> k;
		k--; //for 1 based indexing
		cout << quickSelect(arr, 0, n - 1, k) << endl;
	}
	return 0;
}