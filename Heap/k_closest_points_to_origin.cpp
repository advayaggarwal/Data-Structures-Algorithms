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

//Using Max Heap
//Time complexity - O(N*logK)
vector<vi> kClosest(vector<vi>&points, int k)
{
	int n = points.size();

	priority_queue<pair<int, pii>>maxHeap; //{distance, {x,y}}

	for (int i = 0; i < n; i++)
	{
		int x = points[i][0];
		int y = points[i][1];
		int distance = x * x + y * y; //no need to do square root
		maxHeap.push({distance, {x, y}});

		if (maxHeap.size() > k)	maxHeap.pop();
	}

	vector<vi>res;

	//Max Heap now contains K closest elements
	while (!maxHeap.empty())
	{
		int x = maxHeap.top().second.first;
		int y = maxHeap.top().second.second;

		res.push_back({x, y});
		maxHeap.pop();
	}

	return res;
}

int main()
{
	starter();

	int n, k;
	cin >> n >> k;

	vector<vi>points(n, vi(2));
	cin >> points;

	vector<vi>res = kClosest(points, k);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i][0] << " " << res[i][1] << endl;
	}

	return 0;
}