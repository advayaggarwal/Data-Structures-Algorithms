//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root)   return false;
        return helper(root, targetSum);
    }

    bool helper(TreeNode *root, int target)
    {
        target -= root->val;

        if (!root->left && !root->right)
        {
            return target == 0;
        }

        bool ans1 = false, ans2 = false;

        if (root->left)  ans1 = helper(root->left, target);
        if (root->right) ans2 = helper(root->right, target);

        return (ans1 || ans2);
    }
};

//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root)   return false;
        if (!root->left && !root->right) return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val);
    }
};