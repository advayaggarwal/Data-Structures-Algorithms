// Idea is if we ignore some x, then ignore all x in the vector, for that, first we have to sort the vector, to make
// all the duplicates adjacent
// Else everything is same as Subset I


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, nums, temp, ans, false);
        return ans;

    }

    void helper(int i, vector<int>&nums, vector<int>temp, vector<vector<int>>&ans, bool prev_taken)
    {
        if (i == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        helper(i + 1, nums, temp , ans, false);

        if (i > 0 && nums[i] == nums[i - 1] && !prev_taken)  return; //both the number are same, and previously we ignored it,
        //so have to ignore now also

        temp.push_back(nums[i]);
        helper(i + 1, nums, temp , ans, true);
        temp.pop_back();



    }
};