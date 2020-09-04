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

int gcd(int a, int b)
{
	while (b != 0)
	{
		int remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

void rotate(int arr[], int n, int d) // Time complexity = O(d*(n/d)) i.e. O(n), Space complexity = O(1)
{
	int g_c_d = gcd(n, d);
	d = d % n; // To handle if d >= n
	int i;
	for (i = 0; i < g_c_d; i++) // This for loop will run max of d times
	{
		int temp = arr[i];
		int j = i;
		while (1) // This while loop will run for n/d times as we are adding d to i til it becomes greater or equal to n
		{
			int k = j + d;
			if (k >= n) k = k - n;
			if (k == i) break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

int main()
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