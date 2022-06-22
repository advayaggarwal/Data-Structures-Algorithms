//Recursive Inorder
//Time complexity - O(n1+n2)
//Space complexity - O(n1+n2)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int>res;
        vector<int>t1, t2;

        inorder(root1, t1);
        inorder(root2, t2);

        int n1 = t1.size(), n2 = t2.size();

        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (t1[i] < t2[j])   res.push_back(t1[i++]);
            else res.push_back(t2[j++]);
        }

        while (i < n1) res.push_back(t1[i++]);
        while (j < n2) res.push_back(t2[j++]);

        return res;
    }

    void inorder(TreeNode *root, vector<int>&t)
    {
        if (!root)   return;

        inorder(root->left, t);
        t.push_back(root->val);
        inorder(root->right, t);
    }
};


//Iterative Inorder
//Time complexity - O(n1+n2)
//Space complexity - O(h1+h2)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int>res;
        stack<TreeNode*>s1, s2;

        while (root1 or root2 or !s1.empty() or !s2.empty())
        {
            while (root1)
            {
                s1.push(root1);
                root1 = root1->left;
            }

            while (root2)
            {
                s2.push(root2);
                root2 = root2->left;
            }

            if (s2.empty() or (!s1.empty() && s1.top()->val <= s2.top()->val))
            {
                res.push_back(s1.top()->val);
                root1 = s1.top()->right;
                s1.pop();
            }

            else
            {
                res.push_back(s2.top()->val);
                root2 = s2.top()->right;
                s2.pop();
            }
        }

        return res;
    }
};