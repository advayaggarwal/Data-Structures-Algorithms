//Time complexity - O(logn)
//Space complexity - O(logn)
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root)	return NULL;

		if (root->val > p->val and root->val > q->val)	return lowestCommonAncestor(root->left, p, q);

		else if (root->val < p->val and root->val < q->val)	return lowestCommonAncestor(root->right, p, q);

		return root;
	}
};