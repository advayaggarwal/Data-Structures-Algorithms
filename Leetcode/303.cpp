//Time complexity - O(n) for precomputation, and O(1) per query
//Space complexity - O(n)
class NumArray {
public:
    vector<int>prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum = vector<int>(nums.size() + 1);

        for (int i = 1; i <= nums.size(); i++)  prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    int sumRange(int left, int right) {
        left++; right++;
        return prefixSum[right] - prefixSum[left - 1];
    }
};