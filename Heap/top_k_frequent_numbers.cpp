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

//Using Heap
//Time complexity - O(n*logk)
//Space complexity - O(n)
void topKFrequent(vi &v, int k)
{
	int n = v.size();

	unordered_map<int, int>m; //{element, freq}

	for (int i = 0; i < n; i++)	m[v[i]]++;

	priority_queue<pii, vector<pii>, greater<pii>>minHeap;

	for (auto p : m)
	{
		minHeap.push({p.second, p.first});//because sorting is done on the basis of first,
		//otherwise we had to make a custom comparator

		if (minHeap.size() > k)	minHeap.pop();
	}

	//Now Min Heap contains top k frequent elements

	while (!minHeap.empty())
	{
		cout << minHeap.top().second << " ";
		minHeap.pop();
	}
}

//Using Bucket Sort
//Intuition - We know that for n size array frequency lies in range [1, n]
//Time complexity - O(n)
//Space complexity - O(n)
vi topKFrequentElements(vi &v, int k)
{
	int n = v.size();

	unordered_map<int, int>m; //{element, freq}

	for (int i = 0; i < n; i++)	m[v[i]]++;

	vector<vi>bucket(n + 1); //for each frequency we are storing vector of elements

	//bucket[i] is having the elements which have frequency i

	for (auto p : m)
	{
		bucket[p.second].push_back(p.first);
	}

	vi res;
	for (int i = n; i > 0 && k; i--)
	{
		k -= bucket[i].size();

		for (int j = 0; j < bucket[i].size(); j++)	res.push_back(bucket[i][j]);
	}

	return res;
}


int main()
{
	starter();

	int n, k;
	cin >> n >> k;

	vi v(n);
	cin >> v;

	topKFrequent(v, k);

	vi res = topKFrequentElements(v, k);

	cout << endl << res;

	return 0;
}