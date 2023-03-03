//Using range of values allowed for root
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MIN, INT_MAX);
    }

    bool isBST(TreeNode *root, long long int l, long long int r)
    {
        if (!root)  return true;

        if (l > r) return false;

        if (root->val < l or root->val > r) return false;

        return isBST(root->left, l, 1LL * root->val - 1) and isBST(root->right, 1LL * root->val + 1, r);
    }
};

//Using inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode *prev = NULL;

        bool isBST = true;
        inorder(root, prev, isBST);
        return isBST;
    }

    void inorder(TreeNode *root, TreeNode* &prev, bool &isBST)
    {
        if (!root)  return;

        inorder(root->left, prev, isBST);

        if (prev and root->val <= prev->val)
        {
            isBST = false;
            return;
        }
        prev = root;

        inorder(root->right, prev, isBST);
    }

};