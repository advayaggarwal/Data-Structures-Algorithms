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

//Using custom comparator
void frequencySort(vi v)
{
	unordered_map<int, int>count;

	for (int i = 0; i < v.size(); i++)	count[v[i]]++;

	//Using lambda expression
	sort(v.begin(), v.end(), [&](int a, int b) //[&] : captures all external variables by reference
	{
		if (count[a] == count[b])	return a > b;
		return count[a] < count[b];
	});

	cout << v;
}

//Using Min Heap

void frequency_sort(vi &v)
{
	unordered_map<int, int>count;
	int n = v.size();

	for (int i = 0; i < n; i++)	count[v[i]]++;

	priority_queue<pii, vector<pii>, greater<pii>>minHeap;

	for (auto p : count)
	{
		minHeap.push({p.second, p.first});
	}

	while (!minHeap.empty())
	{
		int freq = minHeap.top().first;
		int ele = minHeap.top().second;

		minHeap.pop();

		while (freq--)	cout << ele << " ";
	}
}

int main()
{
	starter();

	int n;
	cin >> n;

	vi v(n);
	cin >> v;

	frequencySort(v);

	cout << endl;

	frequency_sort(v);

	return 0;
}