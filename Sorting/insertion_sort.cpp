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

//Time complexity
//Worst case, when elements are sorted in reverse order, complexity -> O(n^2)
//Best case is when elements are already sorted, complexity -> O(n), in none of the iteration we will go into while loop
//Inplace as space complexity -> O(1)
//Stable as we are checking if arr[j] > key


void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1; // start of sorted region
		while (j >= 0 && arr[j] > key) //shift
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	starter();
	int n, i;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++)	cin >> arr[i];
	insertion_sort(arr, n);
	for (i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}