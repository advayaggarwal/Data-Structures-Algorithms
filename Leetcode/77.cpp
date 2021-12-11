class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int>subset;
        vector<vector<int>>combinations;

        helper(1, n, subset, combinations, k);

        return combinations;
    }

    void helper(int index, int n, vector<int>&subset, vector<vector<int>>&combinations, int k)
    {

        if (subset.size() == k)
        {
            combinations.push_back(subset);
            return ;
        }

        if (index > n)            return;

        helper(index + 1, n, subset, combinations, k);

        subset.push_back(index);
        helper(index + 1, n, subset, combinations, k);
        subset.pop_back();
    }
};