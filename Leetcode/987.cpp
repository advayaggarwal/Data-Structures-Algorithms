class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)   return {};

        vector<vector<int>>ans;
        queue<pair<TreeNode*, pair<int, int>>>q; //{Node, {distance, level}}
        map<int, map<int, multiset<int>>>m; //{distance, {level, values}}
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int distance = p.second.first;
            int level = p.second.second;

            m[distance][level].insert(temp->val);

            if (temp->left)  q.push({temp->left, {distance - 1, level + 1}});
            if (temp->right) q.push({temp->right, {distance + 1, level + 1}});

        }

        for (auto p : m)
        {
            vector<int>temp;

            for (auto e : p.second)
            {
                for (auto ele : e.second)
                {
                    temp.push_back(ele);
                }
            }

            ans.push_back(temp);
        }

        return ans;

    }
};