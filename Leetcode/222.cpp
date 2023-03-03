//Time complexity - O((n)
//Space complexity - O(logn)
class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if (!root)   return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

//Time complexity - O((logn)^2)
//Space complexity - O(logn)
class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if (!root)   return 0;

        int leftSideHeight = sideHeight(root, true);
        int rightSideHeight = sideHeight(root, false);

        if (leftSideHeight == rightSideHeight)   return (1 << leftSideHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int sideHeight(TreeNode *root, bool isLeftSide)
    {
        int height = 0;
        while (root)
        {
            height++;
            if (isLeftSide)  root = root->left;
            else root = root->right;
        }

        return height;
    }
};