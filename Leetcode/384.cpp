//Fisher Yates Algorithm
class Solution {
public:
    vector<int>nums;
    int n;
    Solution(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
    }

    vector<int> reset() //O(1)
    {
        return nums;
    }

    vector<int> shuffle() //O(n)
    {
        vector<int>snums = nums;

        for (int i = n - 1; i > 0; i--)
        {
            int index = rand() % (i + 1); //returns [0,i]
            swap(snums[i], snums[index]);
        }

        return snums;
    }
};