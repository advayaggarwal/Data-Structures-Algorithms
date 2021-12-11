//Recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;

        preorder(root, res);

        return res;
    }

    void preorder(TreeNode *root, vector<int>&res)
    {
        if (!root)   return;

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};

//Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        if (!root)   return {};

        vector<int>preorder;
        stack<TreeNode*>s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();

            preorder.push_back(node->val);

            if (node->right) s.push(node->right);
            if (node->left)  s.push(node->left);
        }

        return preorder;
    }
};