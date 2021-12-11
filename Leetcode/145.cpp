//Recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode *root, vector<int>&res)
    {
        if (!root)   return;

        helper(root->left, res);
        helper(root->right, res);

        res.push_back(root->val);
    }
};

//Iterative - using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        if (!root)   return {};

        stack<TreeNode*> s1, s2;
        vector<int>postorder;

        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *node = s1.top();
            s1.pop();

            s2.push(node);

            if (node->left)  s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty())
        {
            postorder.push_back(s2.top()->val);
            s2.pop();
        }

        return postorder;
    }
};

//Iterative - using 1 stack
