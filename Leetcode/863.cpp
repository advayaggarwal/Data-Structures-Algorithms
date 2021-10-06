class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if (k == 0)    return {target->val};

        vector<int>ans;
        unordered_map<TreeNode*, TreeNode*>parent;

        parent[root] = NULL;
        findParent(root, parent);

        unordered_set<int>visited;


        queue<TreeNode*>q;
        q.push(target);

        while (!q.empty() and k)
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                visited.insert(temp->val);

                if (temp->left and visited.find(temp->left->val) == visited.end())
                {
                    q.push(temp->left);
                }

                if (temp->right and visited.find(temp->right->val) == visited.end())
                {
                    q.push(temp->right);
                }

                if (parent[temp] and visited.find(parent[temp]->val) == visited.end())
                {
                    q.push(parent[temp]);
                }
            }

            k--;
        }

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

    void findParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&parent)
    {

        if (!root)   return;

        if (root->left)
        {
            parent[root->left] = root;
            findParent(root->left, parent);
        }

        if (root->right)
        {
            parent[root->right] = root;
            findParent(root->right, parent);
        }

    }

};