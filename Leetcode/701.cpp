//Recursive
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (!root)
        {
            TreeNode *root = new TreeNode(val);
            return root;
        }

        if (root->val < val) root->right = insertIntoBST(root->right, val);

        else root->left = insertIntoBST(root->left, val);

        return root;

    }
};


//Iterative
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode *root, int key)
    {
        TreeNode *curr = root, *node = new TreeNode(key);

        while (curr)
        {
            if (curr->val > key)
            {
                if (curr->left) curr = curr->left;

                else
                {
                    curr->left = node;
                    break;
                }
            }

            else
            {
                if (curr->right)    curr = curr->right;

                else
                {
                    curr->right = node;
                    break;
                }
            }
        }

        return root ? root : node;
    }
};