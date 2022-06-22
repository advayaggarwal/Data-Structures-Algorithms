//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    void recoverTree(TreeNode* root)
    {
        TreeNode *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
        inorder(root, first, mid, last, prev);

        if (first && last)   swap(first->val, last->val);
        else swap(first->val, mid->val);
    }

    void inorder(TreeNode *root, TreeNode* &first, TreeNode* &mid, TreeNode* &last, TreeNode* &prev)
    {
        if (!root)   return;

        inorder(root->left, first, mid, last, prev);

        if (prev && prev->val > root->val)
        {
            if (!first) //This is first violation, mark these two nodes as 'first' && 'mid'
            {
                first = prev;
                mid = root;
            }

            else last = root; //This is second violation, mark this node as 'last'
        }

        prev = root; //Now this will become prev for the next call

        inorder(root->right, first, mid, last, prev);
    }
};