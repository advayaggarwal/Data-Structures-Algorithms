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

//This is optimized bubble sort
// We are checking that if there exists an iteration in which no swap was performed then array is already sorted
//So break the outer for loop, i.e. no need of further iterations
//Worst case Time complexity -> O(n^2)
//Best case Time complexity -> O(n)
//Stable, as we will only swap when arr[j] > arr[j+1]
//Inplace as space complexity -> O(1)

void bubble_sort(int arr[], int n)
{
	bool swap;
	//iterations
	for (int i = 0; i < n - 1; i++)
	{
		swap = false;
		//comparisons
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap = true;
			}
		}
		if (swap == false)
		{
			break;
		}
	}
}

int main()
{
	starter();
	int n, i;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++)	cin >> arr[i];
	bubble_sort(arr, n);
	for (i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}