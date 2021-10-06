//By using nums vector
class Solution {
public:

    void helper(int index, int target, int k, vector<int>&nums, vector<int>&sol, vector<vector<int>>&res)
    {

        if (target == 0  and sol.size() == k) //we've to take k elements
        {
            res.push_back(sol);
            return;
        }

        if (target < 0)  return ;
        if (index == nums.size())    return;

        //skip the index th element
        helper(index + 1, target, k, nums, sol, res);

        //take the index th element
        sol.push_back(nums[index]);
        helper(index + 1, target - nums[index], k, nums, sol, res);
        sol.pop_back(); //backtracking
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        if (n > 45)  return {}; //In the ques it is given that we've to take no from 1-9 and each number is used at most once
        // So sum greater than 45 can never be achieved as 1+2+3+4+5+6+7+8+9 = 45
        vector<int>nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int>sol;
        vector<vector<int>>res;

        helper(0, n, k, nums, sol, res);

        return res;
    }
};


//Without using nums vector
class Solution {
public:

    void helper(int num, int target, int k, vector<int>&sol, vector<vector<int>>&res)
    {

        if (target == 0  and k == 0)
        {
            res.push_back(sol);
            return;
        }

        if (target < 0 or k < 0)  return ;
        if (num > 9)    return;

        //skip the index th element
        helper(num + 1, target, k, sol, res);

        //take the index th element
        sol.push_back(num);
        helper(num + 1, target - num, k - 1, sol, res);
        sol.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        if (n > 45)  return {};

        vector<int>sol;
        vector<vector<int>>res;

        helper(1, n, k, sol, res);

        return res;
    }
};