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

int first_occurrence(int arr[], int n, int ele)
{
	int start = 0;
	int end = n - 1;
	int index = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (ele == arr[mid])
		{
			index = mid;
			end = mid - 1;
		}
		else if (ele < arr[mid])	end = mid - 1;
		else start = mid + 1;
	}
	return index;
}

int last_occurrence(int arr[], int n, int ele)
{
	int start = 0;
	int end = n - 1;
	int index  = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (ele == arr[mid])
		{
			index = mid;
			start = mid + 1;
		}
		else if (ele < arr[mid])	end = mid - 1;
		else start = mid + 1;
	}
	return index;
}

int count_occurrences(int arr[], int n, int ele)
{
	int first = first_occurrence(arr, n, ele);
	int last = last_occurrence(arr, n, ele);
	return (last - first + 1);
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)	cin >> arr[i];
	int ele;
	cin >> ele;
	int res = count_occurrences(arr, n, ele);
	cout << res;
	return 0;
}