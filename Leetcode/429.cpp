//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>>res;
        if (!root)   return res;
        queue<Node*>q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            vector<int>level;
            while (sz--)
            {
                Node *n = q.front();
                q.pop();
                level.push_back(n->val);
                vector<Node*>ch = n->children;

                for (auto nodes : ch)
                {
                    q.push(nodes);
                }
            }

            res.push_back(level);
        }

        return res;
    }
};