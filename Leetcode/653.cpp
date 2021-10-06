//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root, v);

        bool possible = false;

        int n = v.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            if (v[i] + v[j] == k)
            {
                possible = true;
                break;
            }

            else if (v[i] + v[j] < k)   i++;

            else j--;
        }

        return possible;
    }

    void inorder(TreeNode *root, vector<int>&v)
    {
        if (!root)   return;

        inorder(root->left, v);

        v.push_back(root->val);

        inorder(root->right, v);
    }
};

//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)  return false;

        stack<TreeNode*>s1, s2;

        pushElements(root, s1, true);
        pushElements(root, s2, false);

        while (!s1.empty() && !s2.empty() && s1.top()->val < s2.top()->val)
        {
            int x = s1.top()->val;
            int y = s2.top()->val;

            if (x + y == k) return true;

            else if (x + y < k)
            {
                TreeNode *temp = s1.top();
                s1.pop();
                pushElements(temp->right, s1, true);
            }

            else
            {
                TreeNode *temp = s2.top();
                s2.pop();
                pushElements(temp->left, s2, false);
            }
        }

        return false;
    }
    void pushElements(TreeNode *root, stack<TreeNode*>&s, bool l_direction)
    {
        if (l_direction)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
        }

        else
        {
            while (root)
            {
                s.push(root);
                root = root->right;
            }
        }
    }
};