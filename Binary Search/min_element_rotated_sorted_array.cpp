/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)

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

int min_ele(int arr[], int n)
{
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		if (arr[start] <= arr[end])	return arr[start];
		int mid = start + (end - start) / 2;
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;
		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])	return arr[mid];
		else if (arr[start] <= arr[mid])	start = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)	cin >> arr[i];
	cout << min_ele(arr, n);
	return 0;
}