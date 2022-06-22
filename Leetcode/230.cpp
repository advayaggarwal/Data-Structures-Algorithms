//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;

        inorder(root, ans);
        return ans[k - 1];
    }

    void inorder(TreeNode *root, vector<int>&ans)
    {
        if (!root)   return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

};


//Time complexity - O(k), not doing complete inorder traversal, as soon as we get the kth element, we stop
//Space complexity - O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;

        inorder(root, ans, k);
        return ans;
    }

    void inorder(TreeNode *root, int &ans, int &k)
    {
        if (!root)  return ;

        if (k <= 0)    return; //optimisation, won't traverse further if we get kth element

        inorder(root->left, ans, k);

        k--;

        if (k == 0)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, ans, k);
    }
};