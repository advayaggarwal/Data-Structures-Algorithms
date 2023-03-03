//Time complexity - O(n)
//Space complexity - O(h)
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root)
    {
        vector<int>freq(10);
        return helper(root, freq);
    }

    int helper(TreeNode* root, vector<int>&freq)
    {
        freq[root->val]++;
        if (!root->left && !root->right)
        {
            int odd_count = 0;
            for (int i = 1; i < 10; i++)
            {
                if (freq[i] & 1) odd_count++;
            }
            freq[root->val]--;
            return odd_count == 0 or odd_count == 1;
        }

        int ans = 0;
        if (root->left)  ans += helper(root->left, freq);
        if (root->right) ans += helper(root->right, freq);
        freq[root->val]--;

        return ans;
    }
};

//Using integer for storing frequencies
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root)
    {
        return helper(root, 0);
    }

    int helper(TreeNode* root, int path)
    {
        path ^= (1 << root->val);
        if (!root->left && !root->right) return (path & (path - 1)) == 0;
        int ans = 0;
        if (root->left)  ans += helper(root->left, path);
        if (root->right) ans += helper(root->right, path);
        return ans;
    }
};