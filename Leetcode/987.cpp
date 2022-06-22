//Using Levelorder Traveral
//Time complexity - O(nlogn)
//Space complexity - O(n)
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

//Using Preorder Traveral
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, map<int, multiset<int>>>m; //{distance, {level, nodes}}
        preorder(root, 0, 0, m);

        vector<vector<int>>res;

        for (auto p : m)
        {
            vector<int>t;
            for (auto e : p.second)
            {
                for (int x : e.second)    t.push_back(x);
            }
            res.push_back(t);
        }

        return res;
    }

    void preorder(TreeNode *root, int level, int distance, map<int, map<int, multiset<int>>>&m)
    {
        if (!root)   return;

        m[distance][level].insert(root->val);
        preorder(root->left, level + 1, distance - 1, m);
        preorder(root->right, level + 1, distance + 1, m);
    }
};