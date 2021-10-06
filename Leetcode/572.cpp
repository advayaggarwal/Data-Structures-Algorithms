//Time complexity - O(m*n), where m is #nodes in root and n is #nodes in subRoot
//Space complexity - O(n)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (!root and !subRoot)  return true;
        if (!root or !subRoot)   return false;

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->val == subRoot->val)
            {
                if (identical(temp, subRoot))    return true;
            }

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        return false;
    }


    bool identical(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 and !root2)   return true;
        if (!root1 or !root2)    return false;

        if (root1->val == root2->val)    return identical(root1->left, root2->left) and identical(root1->right, root2->right);

        else return false;
    }

};