//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int ans = -1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->right) q.push(node->right);
                if (node->left)  q.push(node->left);
                ans = node->val;
            }
        }

        return ans;
    }
};