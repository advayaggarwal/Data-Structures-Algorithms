//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        queue<pair<TreeNode*, long long int>>q; //{node, index}
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            int sz = q.size();
            int last;
            long long int mmin = q.front().second;
            for (int i = 0; i < sz; i++)
            {
                auto p = q.front();
                q.pop();

                long long int index = p.second - mmin; //to avoid overflow and index starting from 0
                if (i == sz - 1)   last = index;

                if (p.first->left) q.push({p.first->left, 2 * index + 1});
                if (p.first->right) q.push({p.first->right, 2 * index + 2});
            }

            ans = max(ans, last + 1);
        }

        return ans;
    }
};