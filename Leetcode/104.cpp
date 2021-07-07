//Simply calculate height

//DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (!root)   return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));

    }
};


//BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (!root)   return 0;

        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            depth++;
        }
        return depth;
    }
};