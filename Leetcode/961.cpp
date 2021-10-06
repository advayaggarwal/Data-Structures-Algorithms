class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (!root1 and !root2)	return true;

		if (!root1 or !root2)	return false;

		if (root1->val != root2->val)	return false;

		bool ans1 = flipEquiv(root1->left, root2->right);
		bool ans2 = flipEquiv(root1->right, root2->left);
		bool ans3 = flipEquiv(root1->left, root2->left);
		bool ans4 = flipEquiv(root1->right, root2->right);

		return (ans1 and ans2) or (ans3 and ans4);
	}
};