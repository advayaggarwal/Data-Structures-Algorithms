//DP
//Time complexity - O(n*k*sum*mini)
//Space complexity - O(n*k*sum*mini)
class Solution {
public:
	int mod = 1e9 + 7;
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
	{
		unordered_map<string, int>dp;
		return helper(0, n, speed, efficiency, k, 0, INT_MAX, dp);
	}

	int helper(int i, int n, vector<int>&speed, vector<int>&efficiency, int k, long long sum, int mini, unordered_map<string, int>&dp)
	{
		if (i == n)  return (sum * mini) % mod;
		string key = to_string(i) + "#" + to_string(k) + "#" + to_string(sum) + "#" + to_string(mini);
		if (dp.count(key))   return dp[key];

		int notTake = helper(i + 1, n, speed, efficiency, k, sum, mini, dp), take = 0;
		if (k > 0)   take = helper(i + 1, n, speed, efficiency, k - 1, sum + speed[i], min(mini, efficiency[i]), dp);

		return dp[key] = max(take, notTake);
	}
};


//Greedy using priority_queue
class Solution {
public:
	int mod = 1e9 + 7;
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
	{
		vector<pair<int, int>>v;
		for (int i = 0; i < n; i++)  v.push_back({speed[i], efficiency[i]});

		sort(v.begin(), v.end(), [](pair<int, int>&a, pair<int, int>&b) {
			return a.second > b.second;
		});

		priority_queue<int, vector<int>, greater<int>>minHeap; //{speed}
		long long totalSpeed = 0, ans = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			if (minHeap.size() == k)
			{
				int sp = minHeap.top();
				totalSpeed -= sp;
				minHeap.pop();
			}

			minHeap.push(v[i].first);
			totalSpeed += v[i].first;
			ans = max(ans, totalSpeed * v[i].second);
		}

		return ans % mod;
	}
};