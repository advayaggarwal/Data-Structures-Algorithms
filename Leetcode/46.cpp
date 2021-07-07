//Time complexity - O(n*n!)
//Space complexity - O(n), considering recursive stack and not considering res vector

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        permutations(nums, 0, n, res);
        return res;
    }

    void permutations(vector<int>nums, int index, int n, vector<vector<int>>&res)
    {
        if (index == n)
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {
            swap(nums[i], nums[index]);
            permutations(nums, index + 1, n, res);
            //swap(nums[i], nums[index]); //no need as vector is pass by value
        }
    }

};