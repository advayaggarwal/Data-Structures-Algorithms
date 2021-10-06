//Recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 and !root2)   return true;

        if (!root1 or !root2)    return false;

        return (root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
    }

};


//Iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        queue<TreeNode*>q;

        if (!root->left and !root->right)    return true;

        if (!root->left or !root->right) return false;

        q.push(root);
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp1 = q.front();
            q.pop();
            TreeNode *temp2 = q.front();
            q.pop();

            if (!temp1 and !temp2)   continue;
            if (!temp1 or !temp2)    return false;

            if (temp1->val != temp2->val)    return false;

            q.push(temp1->left);
            q.push(temp2->right);
            q.push(temp1->right);
            q.push(temp2->left);
        }

        return true;
    }
};