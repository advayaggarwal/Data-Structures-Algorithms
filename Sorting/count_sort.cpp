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

//Time complexity, Worst case -> O(n+k)
// n = size of array
// k = max_value
//Ex- n = 4, k = 100000 -> O(k)
//Ex- n=1000, k = 5 -> O(n)

//It is stable because we started the loop from the end not from the start in finding the sorted array part
//Not in place as space complexity -> O(max_value)

void count_sort(int arr[], int n)
{
	int i;
	//Output array
	int resultant[n];
	//find max element in arr, the size of count array = max_ele + 1, to store the frequency of each element
	int max_value = arr[0];
	//O(n)
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max_value)	max_value = arr[i];
	}
	int count[max_value + 1] = {0};
	//storing frequency of elements of arr
	//O(n)
	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	//O(max_value)
	//storing cumulative frequency
	for (i = 1; i < max_value + 1; i++)
	{
		count[i] += count[i - 1];
	}
	//find the sorted array
	//O(n)
	for (i = n - 1; i >= 0; i--)
	{
		//storing the values in the resultant array
		resultant[count[arr[i]] - 1] = arr[i];
		//decrement the frequency
		count[arr[i]]--;
	}
	//O(n)
	for (i = 0; i < n; i++)	arr[i] = resultant[i];
}

int main()
{
	starter();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)	cin >> arr[i];
	count_sort(arr, n);
	for (int i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}