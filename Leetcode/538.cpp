//Reverse Inorder traversal - Recursive
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;
        add(root, sum);
        return root;
    }

    void add(TreeNode *root, int &sum)
    {
        if (!root)   return ;

        add(root->right, sum);
        sum += root->val;
        root->val = sum;
        add(root->left, sum);
    }
};

//Reverse Inorder traversal - Iterative
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;
        stack<TreeNode*>st;
        TreeNode *node = root;

        while (!st.empty() or node)
        {
            while (node)
            {
                st.push(node);
                node = node->right;
            }

            node = st.top();
            st.pop();
            sum += node->val;
            node->val = sum;

            node = node->left;
        }

        return root;
    }
};