class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        Serialize(root, ans);
        //cout<<ans<<endl;
        return ans;

    }

    void Serialize(TreeNode* root, string &ans) //using preorder
    {
        if (!root)
        {
            ans += "x,";
            return;
        }

        ans += (to_string(root->val) + ",");

        Serialize(root->left, ans);
        Serialize(root->right, ans);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int index = 0;

        return deSerialize(data, index);
    }

    TreeNode* deSerialize(string &data, int &index)
    {
        if (index == data.size())    return NULL;

        if (data[index] == 'x')
        {
            index += 2;
            return NULL;
        }

        bool negative = false;
        if (data[index] == '-')
        {
            index++;
            negative = true;
        }

        int d = 0;

        while (data[index] != ',')
        {
            d = (data[index] - '0') + d * 10;
            index++;
        }
        index++;
        //cout<<d<<endl;

        TreeNode *root;
        if (negative) root = new TreeNode(-d);
        else root = new TreeNode(d);

        root->left = deSerialize(data, index);
        root->right = deSerialize(data, index);

        return root;
    }
};
