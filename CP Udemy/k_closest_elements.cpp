#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x)
{
	priority_queue<pair<int, int>>pq;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		pq.push({abs(x - arr[i]), arr[i]});

		if (pq.size() > k)	pq.pop();
	}
	vector<int>ans;
	while (!pq.empty())
	{
		int t = pq.top().second;
		pq.pop();
		ans.push_back(t);
	}

	sort(ans.begin(), ans.end());
	return ans;
}