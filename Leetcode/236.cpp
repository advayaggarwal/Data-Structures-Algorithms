//Recursive
//Time complexity - O(N)
//Space complexity - O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root or root == p or root == q)  return root;

        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        if (l && r)  return root;

        return l ? l : r;
    }
};

//Using parent array - applicable for all types of trees
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        unordered_map<int, TreeNode*>parent;
        findParent(root, NULL, parent);

        vector<TreeNode*>path1, path2;

        findPath(p, parent, path1);
        findPath(q, parent, path2);

        int m = path1.size(), n = path2.size();
        int i = 0, j = 0;
        for (; i < m - 1 && j < n - 1; i++, j++)
        {
            if (path1[i + 1] != path2[j + 1])    break;
        }

        return path1[i];
    }

    void findParent(TreeNode *root, TreeNode *par, unordered_map<int, TreeNode*>&parent)
    {
        if (!root)   return;

        parent[root->val] = par;

        findParent(root->left, root, parent);
        findParent(root->right, root, parent);
    }

    void findPath(TreeNode *n, unordered_map<int, TreeNode*>&parent, vector<TreeNode*>&p)
    {
        TreeNode *temp = n;
        while (temp)
        {
            p.push_back(temp);
            temp = parent[temp->val];
        }

        reverse(p.begin(), p.end());
    }
};