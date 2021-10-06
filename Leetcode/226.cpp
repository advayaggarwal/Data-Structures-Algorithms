//Recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)   return NULL;

        invert(root);

        return root;
    }

    void invert(TreeNode *root)
    {
        if (!root)   return;

        swap(root->left, root->right);

        invert(root->left);
        invert(root->right);
    }
};

//Iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)   return NULL;

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            swap(temp->left, temp->right);

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        return root;
    }

};