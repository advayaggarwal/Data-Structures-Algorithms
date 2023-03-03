//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        return containsOne(root) ? root : NULL;
    }

    bool containsOne(TreeNode *root)
    {
        if (!root)   return false;

        if (!containsOne(root->left))    root->left = NULL;
        if (!containsOne(root->right))   root->right = NULL;

        return root->val == 1 or root->left or root->right;
    }
};