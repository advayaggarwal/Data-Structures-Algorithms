class Solution {
public:

    void helper(int index, int target, vector<int>&candidates, vector<int>&sol, vector<vector<int>>&res)
    {
        if (target == 0)
        {
            res.push_back(sol);
            return;
        }

        if (target < 0)  return ;

        if (index == candidates.size())  return; //no elements left

        //skip the index th element
        helper(index + 1, target, candidates, sol, res);

        //take the index th element, but don't skip as we may need it further
        sol.push_back(candidates[index]);
        helper(index, target - candidates[index], candidates, sol, res);
        sol.pop_back(); //backtracking
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>res;
        vector<int>sol;

        helper(0, target, candidates, sol , res);

        return res;
    }
};