class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>ans;
        vector<int>path;

        findPaths(root, targetSum, ans, path);

        return ans;

    }


    void findPaths(TreeNode *root, int targetSum, vector<vector<int>>&ans, vector<int>&path)
    {
        if (!root)   return;

        targetSum -= root->val;
        path.push_back(root->val);

        if (!root->left and !root->right and targetSum == 0) //found path having sum as targetSum
        {
            ans.push_back(path);
            return;
        }

        if (root->left)
        {
            findPaths(root->left, targetSum, ans, path);
            path.pop_back();
        }

        if (root->right)
        {
            findPaths(root->right, targetSum, ans, path);
            path.pop_back();
        }
    }
};