class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (!p and !q)   return true;

        if (!p and q)    return false;
        if (p and !q)    return false;

        if (p->val == q->val)
        {
            bool ans1 =  isSameTree(p->left, q->left);
            bool ans2 = isSameTree(p->right, q->right);
            return ans1 and ans2;
        }

        else return false;

    }
};