class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>&nums, int low, int high)
    {
        if (low > high)  return NULL;

        int mid = (low + high) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildTree(nums, low, mid - 1);
        root->right = buildTree(nums, mid + 1, high);

        return root;
    }
};