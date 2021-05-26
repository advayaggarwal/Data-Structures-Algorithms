/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}


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


int largest_subarray_K(vi &arr, int k)
{
	int n = arr.size();
	int i = 0, j = 0, sum = 0, mx = INT_MIN;
	while (j < n)
	{
		sum += arr[j];
		if (sum < k)	j++; //add more elements to the current window
		else if (sum == k) //got the required sum, calculate the window size
		{
			mx = max(mx, j - i + 1);
			cout << i << " " << j << endl;
			j++;
		}
		else //sum greater than k, then we have to remove the starting elements i.e. decrease the window size
		{
			while (sum > k)
			{
				sum -= arr[i];
				i++;
			}

			if (sum == k) //it may be possible that after decreasing the sum, we may get the required sum
			{
				mx = max(mx, j - i + 1);
				cout << i << " " << j << endl;
			}
			j++;
		}
	}

	return mx;
}

int main()
{
	starter();
	int n, k;
	cin >> n >> k;
	vi arr(n);
	cin >> arr;
	cout << largest_subarray_K(arr, k);

	return 0;
}