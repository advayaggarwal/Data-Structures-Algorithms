//Recursive
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(res, root);
        return res;
    }

    void helper(vector<int>&res, TreeNode* root)
    {
        if (!root)   return ;

        helper(res, root->left);

        res.push_back(root->val);

        helper(res, root->right);
    }
};

//Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>inorder;

        TreeNode *node = root;
        stack<TreeNode*>s;

        while (true)
        {
            if (node)
            {
                s.push(node);
                node = node->left;
            }

            else
            {
                if (s.empty())   break;

                node = s.top();
                s.pop();

                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};