class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {

		string path;
		vector<string>ans;
		rootToLeaf(root, path, ans);

		return ans;
	}


	void rootToLeaf(TreeNode *root, string path, vector<string>&ans)
	{
		if (!root)	return;

		path += (to_string(root->val) + "->");

		if (!root->left and !root->right)
		{
			path.pop_back();
			path.pop_back();
			ans.push_back(path);
			return;
		}

		if (root->left)
		{
			rootToLeaf(root->left, path, ans);
		}

		if (root->right)
		{
			rootToLeaf(root->right, path, ans);
		}

	}
};