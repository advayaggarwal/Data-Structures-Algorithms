//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int findTilt(TreeNode* root)
    {
        int res = 0;
        helper(root, res);
        return res;
    }

    int helper(TreeNode* &root, int &res) //Postorder traversal
    {
        if (!root)   return 0;

        int lsum = helper(root->left, res);
        int rsum = helper(root->right, res);
        int sum = root->val + lsum + rsum;

        res += abs(lsum - rsum);
        return sum;
    }
};