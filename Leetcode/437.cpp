//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int total = 0;
    int pathSum(TreeNode* root, int targetSum)
    {
        if (!root)   return 0;

        helper(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return total;
    }

    void helper(TreeNode *root, int targetSum, int sum)
    {
        if (!root)   return;
        sum += root->val;

        if (sum == targetSum)    total++;

        helper(root->left, targetSum, sum);
        helper(root->right, targetSum, sum);
    }
};

//Similar to find #subarrays sum equal k
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int total = 0;
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<int, int>m;
        m[0] = 1;
        helper(root, targetSum, 0, m);
        return total;
    }

    void helper(TreeNode *root, int targetSum, int sum, unordered_map<int, int>&m)
    {
        if (!root)   return;
        sum += root->val;

        if (m.find(sum - targetSum) != m.end())    total += m[sum - targetSum];
        m[sum]++;
        helper(root->left, targetSum, sum, m);
        helper(root->right, targetSum, sum, m);

        m[sum]--;
    }
};