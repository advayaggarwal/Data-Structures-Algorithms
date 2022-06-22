//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();
        unordered_map<int, int>m;
        for (int i = 0; i < n; i++)  m[inorder[i]] = i;
        return build(preorder, 0, n - 1, inorder, 0, n - 1, m);
    }

    TreeNode* build(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, unordered_map<int, int>&m)
    {
        if (preStart > preEnd or inStart > inEnd)    return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = m[preorder[preStart]];
        int numsLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);

        return root;
    }
};