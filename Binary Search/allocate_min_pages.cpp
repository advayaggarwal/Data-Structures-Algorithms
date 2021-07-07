/*
	AUTHOR:			ADVAY AGGARWAL
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
}

bool isPossible(vector<int>&books, int mid, int m)
{
	int n = books.size();
	int students = 1;
	int pages = 0;
	for (int i = 0; i < n; i++)
	{
		if (pages + books[i] <= mid)
		{
			pages += books[i];
		}

		else
		{
			students++;
			pages = books[i];
		}
	}

	return students > m ? false : true;
}

int minPages(vector<int> &books, int m) {
	int n = books.size();
	int start = INT_MIN, end = 0;
	for (int i = 0; i < n; i++)
	{
		start = max(start, books[i]);
		end += books[i];
	}
	int ans = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (isPossible(books, mid, m))
		{
			ans = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	return ans;
}

int main()
{
	starter();
	int n, students;
	cin >> n >> students;
	vi books(n);
	cin >> books;

	cout << minPages(books, students);
	return 0;
}