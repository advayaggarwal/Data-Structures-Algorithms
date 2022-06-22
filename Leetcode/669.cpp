//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (!root)   return NULL;

        TreeNode *leftNode = trimBST(root->left, low, high);
        if (leftNode != root->left)  root->left = leftNode;

        TreeNode *rightNode = trimBST(root->right, low, high);
        if (rightNode != root->right)    root->right = rightNode;

        if (root->val > high or root->val < low) return root->left ? root->left : root->right;

        return root;
    }
};

//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (!root)   return NULL;

        if (root->val < low) return trimBST(root->right, low, high);
        else if (root->val > high)   return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};