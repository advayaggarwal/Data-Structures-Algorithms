//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }

    int helper(TreeNode *root, int &res)
    {
        if (!root) return 0;

        int l = max(0, helper(root->left, res));
        int r = max(0, helper(root->right, res));

        res = max(res, root->val + l + r);

        return root->val + max(l, r);
    }
};