//BFS - Level order traversal
//Time complexity - O(n)
//Space complexity - O(2^h)
class Solution {
public:
    int deepestLeavesSum(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int sum;

        while (!q.empty())
        {
            int sz = q.size();
            sum = 0;
            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return sum;
    }
};

//DFS
//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    int deepestLeavesSum(TreeNode* root)
    {
        int maxLevel = 0, sum = 0;
        preorder(root, 0, maxLevel, sum);
        return sum;
    }

    void preorder(TreeNode *root, int level, int &maxLevel, int &sum)
    {
        if (!root)   return;

        if (level > maxLevel)
        {
            sum = 0;
            maxLevel = level;
        }

        if (level == maxLevel)   sum += root->val;

        preorder(root->left, level + 1, maxLevel, sum);
        preorder(root->right, level + 1, maxLevel, sum);
    }
};