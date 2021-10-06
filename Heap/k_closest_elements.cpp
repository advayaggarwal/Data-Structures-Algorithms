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

//Using sorting
//Time complexity - O(nlogn)
//Space complexity- O(n)
void brute(vi &v, int k, int x)
{
	vector<pair<int, int>>distance; //{distance, element}

	for (int i = 0; i < v.size(); i++)
	{
		distance.push_back({abs(v[i] - x), v[i]});
	}

	sort(distance.begin(), distance.end());

	for (int i = 0; i < k; i++)
	{
		cout << distance[i].second << " ";
	}
}

//Using Max Heap
//Time complexity - O(nlogk)
//Space complexity- O(k)
void kClosest(vi &v, int k, int x)
{
	priority_queue<pii> maxHeap; //{distance, element}

	for (int i = 0; i < v.size(); i++)
	{
		maxHeap.push({abs(x - v[i]), v[i]});

		if (i >= k)
		{
			maxHeap.pop();
		}
	}

	while (!maxHeap.empty())
	{
		cout << maxHeap.top().second << " ";
		maxHeap.pop();
	}
}

int main()
{
	starter();

	int n, k, x;
	cin >> n >> k >> x;

	vi v(n);
	cin >> v;

	brute(v, k, x);
	cout << endl;
	kClosest(v, k, x);

	return 0;
}