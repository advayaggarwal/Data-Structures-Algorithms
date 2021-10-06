// Do level order traversal, and in each level, put the last node of that level into the result

//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if (!root)   return {};

        vector<int>res;

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            res.push_back(q.back()->val);
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return res;
    }
};

// DFS, modified preorder traversal
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL) return ;
        if (res.size() < level) res.push_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};