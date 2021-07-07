//DFS
class Solution {
public:
    int minDepth(TreeNode* root) {

        if (!root)   return 0;
        if (!root->left and !root->right)    return 1;

        if (!root->left) return 1 + minDepth(root->right);

        if (!root->right)    return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));

    }
};

//BFS
//During level order traversal the first leaf node will give the minimum depth

class Solution {
public:
    int minDepth(TreeNode* root) {

        if (!root)   return 0;

        queue<TreeNode*>q;
        q.push(root);
        int depth = 1;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (!temp->left and !temp->right) //leaf node
                {
                    return depth;
                }

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);

            }

            depth++;
        }

        return 0;
    }
};