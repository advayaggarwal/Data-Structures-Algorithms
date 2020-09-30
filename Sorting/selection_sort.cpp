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

//Worst case complexity -> O(n^2)
//Best case complexity -> O(n^2), even if array is sorted we can't get rid of inner loop, just it will not go inside if condition
//Inplace as space complexity -> O(1)
//Not stable because we are simply swapping the ith number with the smallest number in the unsorted region

void selection_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i; //minimum element from unsorted region is at min_index
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_index]) //if we found ele less than current min, change min_index to that location
			{
				min_index = j;
			}
		}
		//found the index of the min element so place it at the start of unsorted region by swapping
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}

int main()
{
	starter();
	int n, i;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++) cin >> arr[i];
	selection_sort(arr, n);
	for (i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}