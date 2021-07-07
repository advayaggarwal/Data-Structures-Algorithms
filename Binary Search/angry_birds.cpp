/*
	AUTHOR:			ADVAY AGGARWAL
*/
//Binary search (predicate function)
//Time complexity - O(n*log(end-start))

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

bool isPossible(int mid, vi &nests, int b, int n) //O(n) function
{
	b--;
	int previous_bird_index = 0;
	for (int i = 1; i < n; i++)
	{
		if ((nests[i] - nests[previous_bird_index]) >= mid)
		{
			b--;
			previous_bird_index = i;
		}
		if (b == 0)	return true;
	}

	return false;
}

int main()
{
	starter();
	int n, b;
	cin >> n >> b;
	vi nests(n);
	cin >> nests;
	//if nests not sorted, sort it first
	sort(nests.begin(), nests.end());
	int start = 0, end = (nests[n - 1] - nests[0]);
	int ans = -1;
	while (start <= end) //search space is end-start
	{
		int mid = start + (end - start) / 2;

		if (isPossible(mid, nests, b, n))
		{
			ans = mid;
			start = mid + 1;
		}

		else	end = mid - 1;
	}

	cout << ans << endl;
	return 0;
}