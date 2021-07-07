/*
	AUTHOR:			ADVAY AGGARWAL
*/

//Worst case Time complexity - O(n)
//Average case Time complexity - O(logn)
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
}

int sparseSearch(vector<string>&v, string key)
{
	int n = v.size();
	int lo = 0;
	int hi = n - 1;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;

		if (v[mid] == "") //we don't know whether we should go left or we should go right, i.e. we don't know
			//So update mid to nearest non empty string by traversing linearly in both the directions
		{
			int left = mid - 1;
			int right = mid + 1;
			while (1)
			{
				if (left < lo && right > hi)	return -1;
				if (left >= lo && v[left] != "")
				{
					mid = left;
					break;
				}

				if (right <= hi && v[right] != "")
				{
					mid = right;
					break;
				}

				left--;
				right++;
			}
		}
		if (v[mid] == key)	return mid;
		else if (v[mid] < key)	lo = mid + 1;
		else hi = mid - 1;
	}

	return -1;
}

int main()
{
	starter();
	vector<string> v{"for", "geeks", "", "", "", "", "ide", "practice", "", "", "", "quiz"};
	string key;
	cin >> key;
	cout << sparseSearch(v, key);
	return 0;
}