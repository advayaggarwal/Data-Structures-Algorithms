//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int sumRootToLeaf(TreeNode* root)
    {
        int ans = 0, sum = 0;
        helper(root, sum, ans);

        return ans;
    }

    void helper(TreeNode *root, int sum, int &ans)
    {
        if (!root)   return;

        sum = (sum << 1) | root->val;

        if (!root->left && !root->right)
        {
            ans += sum;
            return;
        }

        helper(root->left, sum, ans);
        helper(root->right, sum, ans);
    }
};