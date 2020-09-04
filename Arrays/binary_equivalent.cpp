#include<bits/stdc++.h>
using namespace std;

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

int countSetBits(int n)
{
	int count = 0;
	while (n)
	{
		count += (n & 1);
		n = n >> 1;
	}
	return count;
}

int main()
{
	starter();
	int n, i;
	cin >> n;
	int arr[n];
	int number_of_bits = 0;
	int zeroes[n];
	int ones[n];
	vector<int> v0;
	vector<int> v1;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (number_of_bits < floor(log2(arr[i])) + 1) number_of_bits = floor(log2(arr[i])) + 1;
		ones[i] = countSetBits(arr[i]);
	}
	for (i = 0; i < n; i++)	zeroes[i] = number_of_bits - ones[i];
	for (i = 1; i < 1 << n; i++)
	{
		int temp = i;
		int j = 0;
		while (temp)
		{
			if (temp & 1) // if jth bit is set print a[j]
			{
				//printf("%d" , zeroes[j]);
				v0.push_back(zeroes[j]);
			}
			temp >>= 1;
			j++;
		}
		//printf("\n");
	}
	for (i = 1; i < 1 << n; i++)
	{
		int temp = i;
		int j = 0;
		while (temp)
		{
			if (temp & 1) // if jth bit is set print a[j]
			{
				//printf("%d " , ones[j]);
				v1.push_back(ones[j]);
			}
			temp >>= 1;
			j++;
		}
		//printf("\n");
	}
	for (i = 0; i < v0.size(); i++) cout << v0[i] << endl;
	//for (i = 0; i < v1.size(); i++) cout << v1[i] << endl;
	//for (i = 0; i < n; i++)	cout << zeroes[i] << " " << ones[i] << endl;
	return 0;
}