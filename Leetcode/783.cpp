//Inorder traversal
//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    int minDiffInBST(TreeNode* root)
    {
        int ans = INT_MAX, prev = -1;
        traverse(root, ans, prev);
        return ans;
    }

    void traverse(TreeNode *root, int &ans, int &prev)
    {
        if (!root)   return;
        traverse(root->left, ans, prev);
        if (prev != -1)  ans = min(ans, abs(prev - root->val));
        prev = root->val;
        traverse(root->right, ans, prev);
    }
};