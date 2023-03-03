//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int>ans;
        vector<vector<int>>res;
        if (!root)   return res;
        helper(root, targetSum, ans, res);
        return res;
    }

    void helper(TreeNode* root, int targetSum, vector<int>&ans, vector<vector<int>>&res)
    {
        targetSum -= root->val;
        ans.push_back(root->val);

        if (!root->left && !root->right)
        {
            if (targetSum == 0)  res.push_back(ans);
            targetSum += root->val;
            ans.pop_back();
            return;
        }

        if (root->left)  helper(root->left, targetSum, ans, res);
        if (root->right) helper(root->right, targetSum, ans, res);
        targetSum += root->val;
        ans.pop_back();
    }
};