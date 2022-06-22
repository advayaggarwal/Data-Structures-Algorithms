//Time complexity - O((logn)^2)
//Space complexity - O(logn)
class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if (!root)   return 0;

        int lh = height(root, true);
        int rh = height(root, false);

        if (lh == rh)    return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int height(TreeNode *root, bool left)
    {
        int ht = 0;
        while (root)
        {
            ht++;
            if (left)    root = root->left;
            else root = root->right;
        }

        return ht;
    }
};