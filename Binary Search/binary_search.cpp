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

int binary_search(int arr[], int n, int element)
{
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		int mid = start + end - start / 2;
		if (element == arr[mid]) return mid;
		else if (element < arr[mid]) end = mid - 1;
		else start = mid + 1;
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
	int element;
	cin >> element;
	int ans = binary_search(arr, n, element);
	cout << ans;
	return 0;
}