class Solution {
public:
    unordered_map<int, int>idx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        for (int i = 0; i < n; i++) idx[inorder[i]] = i;
        int end = n - 1;

        return build(postorder, inorder, end, 0, n - 1);
    }

    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int &end, int ins, int ine)
    {
        if (ins > ine)   return NULL;

        TreeNode *root = new TreeNode(postorder[end]);
        int mid = idx[postorder[end]];
        end--;

        root->right = build(postorder, inorder, end, mid + 1, ine);
        root->left = build(postorder, inorder, end, ins, mid - 1);

        return root;
    }
};