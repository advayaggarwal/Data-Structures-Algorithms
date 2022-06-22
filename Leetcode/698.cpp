//Time complexity - O(n^k)
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = 0;
        for (int &num : nums)    sum += num;

        if (sum % k != 0)  return false;
        int n = nums.size();
        if (n < k)   return false;

        int subsetSum = sum / k;

        vector<bool>visited(n);
        return canPartition(0, k, nums, visited, 0, subsetSum);
    }

    bool canPartition(int i, int k, vector<int>&nums, vector<bool>&visited, int currSum, int subsetSum)
    {
        if (k == 0)  return true;
        if (currSum > subsetSum) return false;
        if (currSum == subsetSum)   return canPartition(0, k - 1, nums, visited, 0, subsetSum);

        for (int j = i; j < nums.size(); j++)
        {
            if (visited[j])  continue;
            visited[j] = true;
            if (canPartition(j + 1, k, nums, visited, currSum + nums[j], subsetSum))  return true;
            visited[j] = false;
        }

        return false;
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int K) {
        int N = nums.size();
        if (K == 1) return true;
        if (N < K) return false;
        int sum = 0;
        for (int i = 0; i < N; i++) sum += nums[i];
        if (sum % K != 0) return false;

        int subset = sum / K;
        int subsetSum[K];
        bool taken[N];

        for (int i = 0; i < K; i++) subsetSum[i] = 0;
        for (int i = 0; i < N; i++) taken[i] = false;

        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;

        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
    }

    bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == K - 2) return true;
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if (nxt) return true;
            }
        }
        return false;
    }
};

//Bitwise DP
//Time complexity - O(n*2^n)
//Space complexity - O(2^n)
class Solution {
public:
    int dp[(1 << 16) + 2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        fill(dp, dp + (1 << 16) + 2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum / k;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) && dp[mask] + nums[i] <= tar) { // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % tar;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};