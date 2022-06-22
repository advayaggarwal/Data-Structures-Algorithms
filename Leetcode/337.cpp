//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int rob(TreeNode* root)
    {
        map<pair<TreeNode*, bool>, int>dp;
        return helper(root, true, dp);
    }

    int helper(TreeNode* root, bool canRob, map<pair<TreeNode*, bool>, int>&dp)
    {
        if (!root)   return 0;
        if (dp.count({root, canRob}))    return dp[ {root, canRob}];

        int op1 = helper(root->left, true, dp) + helper(root->right, true, dp); //don't rob
        int op2 = 0; //rob
        if (canRob) op2 = root->val + helper(root->left, false, dp) + helper(root->right, false, dp);

        return dp[ {root, canRob}] = max(op1, op2);
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int rob(TreeNode* root)
    {
        unordered_map<TreeNode*, int>dp;
        return helper(root, dp);
    }

    int helper(TreeNode* root, unordered_map<TreeNode*, int>&dp)
    {
        if (!root)   return 0;
        if (dp.count(root))    return dp[root];

        int notRob = helper(root->left, dp) + helper(root->right, dp);
        int rob = root->val;
        if (root->left) rob += helper(root->left->left, dp) + helper(root->left->right, dp);
        if (root->right) rob += helper(root->right->left, dp) + helper(root->right->right, dp);

        return dp[root] = max(rob, notRob);
    }
};

//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    int rob(TreeNode* root)
    {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }

    pair<int, int> dfs(TreeNode* root)
    {
        if (!root) return {0, 0};
        auto [leftDontRob, leftRob]   = dfs(root -> left);
        auto [rightDontRob, rightRob] = dfs(root -> right);
        return {
            max(leftDontRob, leftRob) + max(rightDontRob, rightRob),
            root -> val + leftDontRob + rightDontRob
        };
    }
};