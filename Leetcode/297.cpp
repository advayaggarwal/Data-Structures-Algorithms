//Using Preorder
//Time complexity - O(n)
//Space complexity - O(n)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        Serialize(root, ans);
        //cout<<ans<<endl;
        return ans;

    }

    void Serialize(TreeNode* root, string &ans)
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

//Using Levelorder - easy
//Time complexity - O(n)
//Space complexity - O(n)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root)   return "";

        string s;

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (!node)   s += "#,";
            else
            {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (data.size() == 0)  return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")  node->left = NULL;

            else
            {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if (str == "#")  node->right = NULL;

            else
            {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};