class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high) {

		int ans = 0;
		search(root, low, high, ans);

		return ans;
	}

	void search(TreeNode *root, int low, int high, int &ans)
	{
		if (!root)	return;

		if (root->val >= low and root->val <= high)  ans += root->val;
		if (root->val > low) search(root->left, low, high, ans);
		if (root->val < high)    search(root->right, low, high, ans);

	}
};