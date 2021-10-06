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

//K-Way merge
//Time complexity - O(n*k*logk), where n is #elements in one array, k is #arrays
//Space complexity - O(k)
vi mergeKSortedArrays(vector<vi>&arrays)
{
	int k = arrays.size();

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>minHeap;

	//init the heap
	for (int i = 0; i < k; i++)
	{
		minHeap.push({arrays[i][0], {i, 0}}); //Push minimum elements of each array
	}

	vi res;

	//start popping and pushing more elements
	while (!minHeap.empty())
	{
		res.push_back(minHeap.top().first);

		int x = minHeap.top().second.first;
		int y = minHeap.top().second.second;
		minHeap.pop();

		if (y + 1 < arrays[x].size())	minHeap.push({arrays[x][y + 1], {x, y + 1}});
	}

	return res;
}

int main()
{
	starter();

	vector<vi>arrays = {{1, 3, 15}, {2, 4, 6}, {0, 9, 10, 11}};

	vi res = mergeKSortedArrays(arrays);
	cout << res;

	return 0;
}