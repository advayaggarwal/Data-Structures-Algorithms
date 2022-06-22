//Recursive
//Time complexity - O(h)
//Space complexity - O(h)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (!root or root->val == val)    return root;

        else if (root->val < val)    return searchBST(root->right, val);

        else return searchBST(root->left, val);
    }
};

//Iterative
//Time complexity - O(h)
//Space complexity - O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        TreeNode *ans = NULL;

        while (root && root->val != val)
        {
            if (root->val < val) root = root->right;
            else root = root->left;
        }

        if (root)    ans = root;
        return ans;
    }
};