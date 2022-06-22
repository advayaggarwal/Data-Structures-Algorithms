//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        TreeNode *res;
        preorder(original, cloned, target, res);
        return res;
    }

    void preorder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &res)
    {
        if (!original or !cloned)    return;

        if (target->val == cloned->val)
        {
            res = cloned;
            return;
        }

        preorder(original->left, cloned->left, target, res);
        preorder(original->right, cloned->right, target, res);
    }
};