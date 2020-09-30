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

void merge(int arr[], int l, int mid, int r, int n)
{
	//2 pointer approach
	int temp[n];
	int i = l;
	int j = mid + 1;
	//for temp array
	int k = 0;
	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++, k++;
		}
		else
		{
			temp[k] = arr[j];
			j++, k++;
		}
	}
	//Elements left in leftmost array, so simply copying them without checking
	while (i <= mid)
	{
		temp[k] = arr[i];
		i++, k++;
	}
	//Elements left in rightmost array, so simply copying them without checking
	while (j <= r)
	{
		temp[k] = arr[j];
		j++, k++;
	}
	//copying elements back to original array
	//m should be l not 0 because we want ele to be in correct pos wrt original arr not at the 0th index
	for (int m = l, p = 0; m <= r; m++, p++)
	{
		arr[m] = temp[p];
	}
}
//By master's theorem T(n) = 2T(n/2)   +   O(n)   which comes out to be O(nlogn)
//For						division      merge
//Time complexity -> O(nlogn) We are doing logn divisions and for each division we are doing one merge operation which is again O(n), so O(nlogn)
//Worst Case -> O(nlogn)
//Best Case -> O(nlogn), we are not checking after division whether it's already sorted or not, so merging it in O(n)
//Not inplace as space complexity -> O(n), we used temp array with size equal size of arr
//Stable because at the end we have all single elements at one place and during merge operation we are checking if(arr[i]<=arr[j]) we'll take arr[i]
void merge_sort(int arr[], int l, int r, int n)
{
	if (r > l)
	{
		int mid = l + (r - l) / 2;
		//Divide process
		merge_sort(arr, l, mid, n);
		merge_sort(arr, mid + 1, r, n);
		//Merge process
		merge(arr, l, mid, r, n);
	}
}

int main()
{
	starter();
	int n, i;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++)	cin >> arr[i];
	merge_sort(arr, 0, n - 1, n);
	for (i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}