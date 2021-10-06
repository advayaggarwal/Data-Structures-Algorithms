//Reversed Inorder traversal

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {

        int sum = 0;

        helper(root, sum);

        return root;
    }

    void helper(TreeNode *root, int &sum)
    {
        if (!root)   return;

        helper(root->right, sum);

        sum += root->val;
        root->val = sum;

        helper(root->left, sum);
    }
};