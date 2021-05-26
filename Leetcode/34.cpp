//Using STL

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int n = nums.size();
        if (n == 0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int li = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (li < n && nums[li] == target)    res.push_back(li);
        else res.push_back(-1);

        int ui = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (ui <= n && ui != 0  && nums[ui - 1] == target) res.push_back(ui - 1);
        else res.push_back(-1);

        return res;
    }
};


//Without using STL

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int n = nums.size();

        //lower bound
        helper(nums, n, res, target, 0);
        //upper bound
        helper(nums, n, res, target, 1);

        return res;
    }

    void helper(vector<int>&nums, int n, vector<int>&res, int target, int x)
    {

        int l = 0, hi = n - 1;
        int ans = -1;
        while (l <= hi)(nums, n, res, target, 0);
        {
            int mid = l + (hi - l) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                if (x == 0) hi = mid - 1;
                else l = mid + 1;
            }

            else if (nums[mid] > target)   hi = mid - 1;
            else l = mid + 1;
        }
        res.push_back(ans);

    }

};