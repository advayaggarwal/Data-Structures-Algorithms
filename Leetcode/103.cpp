//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)   return {};

        vector<vector<int>>res;

        queue<TreeNode*>q;

        q.push(root);
        int flag = 1;

        while (!q.empty())
        {
            int n = q.size();
            vector<int>level(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                level[i] = temp->val;

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (!flag)   reverse(level.begin(), level.end());

            res.push_back(level);
            flag = !flag;

        }

        return res;
    }
};

//Without using reverse
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>>zigzag;

        if (!root)   return zigzag;

        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int>level(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                int index = leftToRight ? i : n - 1 - i;
                level[index] = temp->val;

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            leftToRight = !leftToRight;
            zigzag.push_back(level);
        }

        return zigzag;
    }
};