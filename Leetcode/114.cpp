//Using preorder traversal
class Solution {
public:
    void flatten(TreeNode* root) {

        if (!root)   return;

        TreeNode *head = NULL, *tail = NULL;

        toLL(root, head, tail);
    }

    void toLL(TreeNode *root, TreeNode* &head, TreeNode* &tail)
    {
        if (!root)   return;

        TreeNode *l = root->left;
        TreeNode *r = root->right;

        if (!head)
        {
            head = root;
        }

        else
        {
            tail->right = root;
        }

        root->left = NULL;
        tail = root;

        toLL(l, head, tail);
        toLL(r, head, tail);
    }
};


//Using reverse postorder traversal
class Solution {
public:
    void flatten(TreeNode* root) {

        if (!root)   return;

        TreeNode *prev = NULL;

        toLL(root, prev);
    }

    void toLL(TreeNode *root, TreeNode* &prev)
    {
        if (!root)   return;

        toLL(root->right, prev);
        toLL(root->left, prev);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};