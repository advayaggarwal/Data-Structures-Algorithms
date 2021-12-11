#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums)
{
	priority_queue<int, vector<int>, greater<int>>minHeap(nums.begin(), nums.end());
	int cost = 0;
	while (minHeap.size() > 1)
	{
		int n1 = minHeap.top();
		minHeap.pop();
		int n2 = minHeap.top();
		minHeap.pop();

		cost += n1 + n2;
		minHeap.push(n1 + n2);
	}

	return cost;
}