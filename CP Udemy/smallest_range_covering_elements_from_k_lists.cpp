#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> nums)
{
	int k = nums.size();

	multiset<pair<int, pair<int, int>>>minHeap; //{value, {index, list no}}
	int low = INT_MIN, hi = INT_MAX, mx = INT_MIN, range = INT_MAX;

	for (int i = 0; i < k; i++)
	{
		sort(nums[i].begin(), nums[i].end());
		minHeap.insert({nums[i][0], {0, i}});
		mx = max(mx, nums[i][0]);
	}

	while (true)
	{
		auto temp = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		if (mx - temp.first < range)
		{
			range = mx - temp.first;
			low = temp.first;
			hi = mx;
		}

		int index = temp.second.first + 1;
		int lno = temp.second.second;

		if (index < nums[lno].size())
		{
			minHeap.insert({nums[lno][index], {index, lno}});
			mx = max(mx, nums[lno][index]);
		}

		else break;
	}

	return {low, hi};
}