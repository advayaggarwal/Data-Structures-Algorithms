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

int countSetBits(int n)		//First Method, Time complexity = O(no. of bits)
{
	int count = 0;
	while (n)
	{
		count += (n & 1); //It will check whether the 0th bit is set or not, after checking we are right shifting by 1 bit
		n = n >> 1;
	}
	return count;
}

int countSetBits2(int n)	//Second Method, Time complexity = O(sizeof(int))
{
	int count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (n & (1 << i)) count++; //& the number with the powers of 2 as in powers of 2 only 1 bit will be set at a time
	}
	return count;
}

int countSetBits_NtoNminus1(int n)	//Brian Kernighan’s Algorithm, Time complexity O(log n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}


int main()
{
	starter();
	int n, ans1, ans2, ans3;
	cin >> n;
	ans1 = countSetBits(n);
	cout << ans1 << endl;
	ans2 = countSetBits2(n);
	cout << ans2 << endl;
	ans3 = countSetBits_NtoNminus1(n);
	cout << ans3;
	return 0;
}
