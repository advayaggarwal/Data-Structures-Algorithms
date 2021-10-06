class Solution {
public:
    unordered_map<int, int>index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();
        int start = 0;
        for (int i = 0; i < n; i++)  index[inorder[i]] = i;
        return build(preorder, inorder, start, 0, n - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &start, int ins, int ine)
    {
        if (ins > ine)   return NULL;

        TreeNode *root = new TreeNode(preorder[start]);
        int mid = index[preorder[start]];
        start++;

        root->left = build(preorder, inorder, start, ins, mid - 1);
        root->right = build(preorder, inorder, start, mid + 1, ine);

        return root;
    }
};