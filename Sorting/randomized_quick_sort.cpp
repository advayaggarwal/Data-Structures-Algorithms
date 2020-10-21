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

int partition(int arr[], int low, int high)
{
	int k = (rand() % (high - low + 1)) + low;
	int pivot = arr[k];
	int pi = low - 1;
	for (int j = low; j <= high; j++)
	{
		if (arr[j] <= pivot)
		{
			pi++;
			int temp  = arr[j];
			arr[j] = arr[pi];
			arr[pi] = temp;
		}
	}
	// int t = arr[pi + 1];
	// arr[pi + 1] = arr[k];
	// arr[k] = t;
	return pi + 1;
}

void randomized_quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		randomized_quick_sort(arr, low, pi - 1);
		randomized_quick_sort(arr, pi + 1, high);
	}
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)	cin >> arr[i];
	randomized_quick_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}