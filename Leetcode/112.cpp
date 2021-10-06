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