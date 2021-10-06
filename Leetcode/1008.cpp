class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int n = preorder.size();
        int i = 0;
        return build(i, n, preorder, INT_MIN, INT_MAX);

    }

    TreeNode* build(int& i, int n, vector<int>& preorder, int l, int r)
    {
        if (i >= n)    return NULL;

        if (preorder[i] >= l  and preorder[i] <= r)
        {
            TreeNode *root = new TreeNode(preorder[i++]);
            root->left = build(i, n, preorder, l, root->val - 1);
            root->right = build(i, n, preorder, root->val + 1, r);
            return root;
        }

        return NULL;
    }
};