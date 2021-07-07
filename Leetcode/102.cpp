//BFS, iterative way
//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (!root)   return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {

            int n = q.size(); //number of nodes in that particular level
            vector<int>level(q.size());

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                level[i] = temp->val;
                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
                q.pop();
            }

            ans.push_back(level);
        }

        return ans;
    }
};


//DFS, recursion, Preorder traversal
//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (!root)   return {};

        vector<vector<int>>res;
        helper(root, 0, res);

        return res;
    }

    void helper(TreeNode *root, int level, vector<vector<int>>&res)
    {
        if (!root)   return;


        if (level == res.size())
        {
            res.push_back({});

        }

        res[level].push_back(root->val);

        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);
    }

};