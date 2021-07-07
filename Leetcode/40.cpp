// Idea is if we ignore some x, then ignore all x in the vector, for that, first we have to sort the vector, to make
// all the duplicates adjacent
// Else everything is same as Combination Sum

class Solution {
public:

    void helper(int index, int target, vector<int>&candidates, vector<int>&sol, vector<vector<int>>&res, bool prev_taken)
    {

        if (target == 0)
        {
            res.push_back(sol);
            return;
        }

        if (target < 0)  return ;
        if (index == candidates.size())  return ;

        //skip the index th element
        helper(index + 1, target, candidates, sol, res, false);

        if (index > 0 and candidates[index] == candidates[index - 1] and !prev_taken)    return;

        //take the index th element
        sol.push_back(candidates[index]);
        helper(index + 1, target - candidates[index], candidates, sol, res, true);
        sol.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int>sol;
        vector<vector<int>>res;

        helper(0, target, candidates, sol, res, false);
        return res;
    }
};