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
#define pii pair<int,int>


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

//Everytime connect ropes which are having least length - Use Min Heap
//Time complexity - O(NlogN)
int minCost(vi &ropes)
{
	int n = ropes.size();

	priority_queue<int, vi, greater<int>>minHeap(ropes.begin(), ropes.end());

	int cost = 0;

	while (minHeap.size() > 1)
	{
		int min1 = minHeap.top();
		minHeap.pop();
		int min2 = minHeap.top();
		minHeap.pop();

		cost += min1 + min2;

		minHeap.push(min1 + min2);
	}

	return cost;
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi ropes(n);
	cin >> ropes;

	cout << minCost(ropes);

	return 0;
}