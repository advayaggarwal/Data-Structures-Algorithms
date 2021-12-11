//Time complexity of - next(), hasNext() - O(1)
//Space complexity - O(n), storing entire inorder traversal
class BSTIterator {
public:
    vector<int>in;
    int n;
    int index;
    BSTIterator(TreeNode* root)
    {
        inorder(root, in);
        index = -1;
        n = in.size();
    }

    int next() //O(1)
    {
        index++;
        return in[index];
    }

    bool hasNext() //O(1)
    {
        return index + 1 < n;
    }

    void inorder(TreeNode *root, vector<int>&in)
    {
        if (!root)   return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
};

//Iterative Inorder Traversal
//Time complexity - average O(1), we are pushing n elements into the stack throughout and there can be at max n next calls
// Therefore n/n = 1 => O(1)
//Space complexity - O(h)
class BSTIterator {

private:
    stack<TreeNode*>s;

public:
    BSTIterator(TreeNode* root)
    {
        insert(root);
    }

    int next() //Average O(1)
    {
        TreeNode *temp = s.top();
        s.pop();

        insert(temp->right);

        return temp->val;
    }

    bool hasNext() //O(1)
    {
        return !s.empty();
    }

private:
    void insert(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
};