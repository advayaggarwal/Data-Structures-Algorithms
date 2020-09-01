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

void rotate_one_by_one(int arr[], int n) //Function to rotate array by one element towards left
{
	int i;
	int temp = arr[0];
	for (i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[n - 1] = temp;
}

void rotate(int arr[], int n, int d) //Function to rotate array by d elements towards left
{
	int i;
	for (i = 0; i < d; i++)
	{
		rotate_one_by_one(arr, n);
	}
}

int main() //Time complexity = O(n*d), Space complexity = O(1)
{
	starter();
	int n, d, i;
	cin >> n >> d;
	int arr[n];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	rotate(arr, n, d);
	for (i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}