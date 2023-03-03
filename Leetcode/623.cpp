//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *n = new TreeNode(val);
            n->left = root;
            return n;
        }

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            depth--;
            if (depth == 0)  break;
            while (sz--)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (depth == 1) //insert nodes below this level
                {
                    if (temp->left)
                    {
                        TreeNode *n = new TreeNode(val);
                        TreeNode *x = temp->left;
                        temp->left = n;
                        n->left = x;
                        q.push(n);
                    }
                    else
                    {
                        TreeNode *n = new TreeNode(val);
                        temp->left = n;
                        q.push(n);
                    }

                    if (temp->right)
                    {
                        TreeNode *n = new TreeNode(val);
                        TreeNode *x = temp->right;
                        temp->right = n;
                        n->right = x;
                        q.push(n);
                    }

                    else
                    {
                        TreeNode *n = new TreeNode(val);
                        temp->right = n;
                        q.push(n);
                    }
                }

                else
                {
                    if (temp->left)  q.push(temp->left);
                    if (temp->right) q.push(temp->right);
                }
            }
        }

        return root;
    }
};


//Same as above but with shorter code
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *n = new TreeNode(val);
            n->left = root;
            return n;
        }

        queue<TreeNode*>q;
        q.push(root);
        int d = 1;

        while (d < depth - 1)
        {
            int sz = q.size();
            d++;
            while (sz--)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;

            temp = node->right;
            node->right = new TreeNode(val);
            node->right->right = temp;
        }

        return root;
    }
};

/*
The idea is to:
In addition to use 1 to indicate attach to left node as required, we can also use 0 to indicate attach to right node;
Time complexity - O(n)
Space complexity - O(n)
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if (d == 0 || d == 1)
        {
            TreeNode* newroot = new TreeNode(v);
            (d ? newroot->left : newroot->right) = root;
            return newroot;
        }

        if (root && d >= 2)
        {
            root->left  = addOneRow(root->left,  v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }

        return root;
    }
};