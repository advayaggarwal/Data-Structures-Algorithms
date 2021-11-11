class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        bool found = false;

        isPossible(root, targetSum, found);
        return found;
    }

    void isPossible(TreeNode *root, int targetSum, bool &found)
    {
        if (!root)   return;

        targetSum -= root->val;

        if (!root->left and !root->right)
        {
            if (targetSum == 0)    found = true;
            return;
        }


        if (root->left)
        {
            isPossible(root->left, targetSum, found);
            if (found)    return;
        }

        if (root->right)
        {
            isPossible(root->right, targetSum, found);
            if (found)    return;
        }
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

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