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

void rotate_array(int arr[], int temp[], int n, int d) //Time complexity = O(n), Space complexity = O(d)
{
	int i;
	for (i = 0; i < (n - d); i++)
	{
		arr[i] = arr[d + i];
	}
	for (i = 0; i < d; i++)
	{
		arr[n - d + i] = temp[i];
	}
}

int main()
{
	starter();
	int n, d, i;
	cin >> n >> d;
	d%=n;
	int arr[n], temp[d];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i < d) temp[i] = arr[i];
	}
	rotate_array(arr, temp, n, d);
	for (i = 0; i < n; i++)	cout << arr[i] << " ";
	return 0;
}
