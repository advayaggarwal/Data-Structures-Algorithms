//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root)
    {
        vector<int>values;
        inorder(root, values);
        TreeNode *res = new TreeNode(0), *temp = res;

        for (int &v : values)
        {
            temp->right = new TreeNode(v);
            temp = temp->right;
        }

        return res->right;
    }

    void inorder(TreeNode *root, vector<int>&values)
    {
        if (!root)   return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
};

//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode *res = new TreeNode(0), *curr = res;
        inorder(root, curr);
        return res->right;
    }

    void inorder(TreeNode* root, TreeNode* &curr)
    {
        if (!root)   return;
        inorder(root->left, curr);
        root->left = NULL;
        curr->right = root;
        curr = root;
        inorder(root->right, curr);
    }
};