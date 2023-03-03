//Using preorder traversal
//Time complexity - O(n)
//Space complexity - O(n)
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
//Time complexity - O(n)
//Space complexity - O(n)
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


//Morris Traversal
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    void flatten(TreeNode* root)
    {
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *pred = curr->left;
                while (pred->right) pred = pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};