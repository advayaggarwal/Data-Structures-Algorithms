
//Bit masking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < (1 << n); i++)
        {
            vector<int>v;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)   v.push_back(nums[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};


//Recursion

class Solution {
public:
    vector<vector<int>>ans;
    void helper(int i, vector<int>&nums, vector<int>&output)
    {
        if (i == nums.size())
        {
            ans.push_back(output);
            return;
        }

        helper(i + 1, nums, output); //don't take the ith element
        output.push_back(nums[i]);
        helper(i + 1, nums, output); //take the ith element
        output.pop_back(); //Backtracking step
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        helper(0, nums, output);
        return ans;
    }
};