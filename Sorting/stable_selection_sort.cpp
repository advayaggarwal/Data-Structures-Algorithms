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

//Time complexity is greater than simple selection sort because we are inserting like we do in insertion sort
//Stable, as after finding the min_index, instead of swapping, the min ele is placed in its position by pushing every other ele one step forward
//Inplace, space complexity -> O(1)

void stable_selection_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_index])	min_index = j;
		}
		int key = arr[min_index];
		while (min_index > i)
		{
			arr[min_index] = arr[min_index - 1];
			min_index--;
		}
		arr[i] = key;
	}
}

int main()
{
	starter();
	int n, i;
	cin >> n;
	int arr[n];
	for (i = 0; i < n; i++)	cin >> arr[i];
	stable_selection_sort(arr, n);
	for (i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}