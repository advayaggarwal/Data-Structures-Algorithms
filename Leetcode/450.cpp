class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root)   return NULL;

        if (root->val == key)
        {
            if (!root->left and !root->right) //No child
            {
                return NULL;
            }

            else if (root->left and root->right) //Both children
            {
                TreeNode *temp = maxElement(root->left);

                root->val = temp->val;

                root->left = deleteNode(root->left, temp->val);

                return root;
            }

            else //1 child
            {
                if (root->left)  return root->left;
                else   return root->right;
            }
        }

        else if (root->val > key)    root->left = deleteNode(root->left, key);

        else root->right = deleteNode(root->right, key);

        return root;

    }

    TreeNode* maxElement(TreeNode* root)
    {
        if (!root->right)    return root;

        return maxElement(root->right);
    }

};