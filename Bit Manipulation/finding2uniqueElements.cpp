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
	//for getting input from input1.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output.txt", "w", stdout);
#endif
}

bool checkIthBit(int n, int i)
{
	if (n & (1 << i)) return true;
	else return false;
}


int makePartition(int a[], int n, int bit_no)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkIthBit(a[i], bit_no)) ans = ans ^ a[i];
	}
	return ans;
}


int SetBit(int n)
{
	int count = 0;
	while (n > 0)
	{
		if ((n & 1)) return count;
		else
		{
			n = n >> 1;
			count++;
		}

	}
}

void find_unique_elements(int a[], int n)
{
	int result = 0, bit_no = 0;
	for (int i = 0; i < n; i++)
	{
		result ^= a[i];
	}
	//cout << result << endl;
	bit_no = SetBit(result);
	int ans1, ans2;
	ans1 = makePartition(a, n, bit_no);
	ans2 = ans1 ^ result;
	cout << ans1 << " " << ans2;
	//cout << bit_no;
}

int main()
{
	starter();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	find_unique_elements(a, n);
	return 0;
}
