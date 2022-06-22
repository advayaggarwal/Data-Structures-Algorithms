//Time complexity - O(n*logn)
//Space complexity - O(n)
class Solution {
public:
    map<pair<TreeNode*, pair<bool, bool>>, int>dp;
    int minCameraCover(TreeNode* root)
    {
        //cam means if current node has camera or not
        //parCam means if parent of current node has camera or not
        return min(solve(root, 1, 0), solve(root, 0, 0));
    }

    int solve(TreeNode *root, bool cam, bool parCam)
    {
        if (!root)
        {
            if (cam) return 1e9;
            return 0;
        }

        if (!root->left && !root->right) //leaf node
        {
            if (cam) return 1;
            else
            {
                if (parCam)  return 0; //if leaf node doesn't need camera and its parent has one then return 0
                return 1e9; //can't cover this leaf node so return inf
            }
        }

        if (dp.count({root, {cam, parCam}}))  return dp[ {root, {cam, parCam}}];

        if (cam) //place camera at current node, left and right child may or may not have camera
        {
            return dp[ {root, {cam, parCam}}] = 1 + min(solve(root->left, 1, 1), solve(root->left, 0, 1)) +
                                                min(solve(root->right, 1, 1), solve(root->right, 0, 1));
        }

        else if (parCam) //don't place camera at current node given that parent has camera, but left and right child may or may not have camera
        {
            return dp[ {root, {cam, parCam}}] = min(solve(root->left, 1, 0), solve(root->left, 0, 0)) +
                                                min(solve(root->right, 1, 0), solve(root->right, 0, 0));
        }

        else //don't place camera at current node and parent also don't have camera, so have to force at least 1 child to have camera
        {
            int op1 = solve(root->left, 1, 0) + min(solve(root->right, 0, 0), solve(root->right, 1, 0)); //forcing left to have camera, right may or may not have camera
            int op2 = solve(root->right, 1, 0) + min(solve(root->left, 0, 0), solve(root->left, 1, 0)); //forcing right to have camera, left may or may not have camera
            return dp[ {root, {cam, parCam}}] = min(op1, op2);
        }
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int cameras;
    int minCameraCover(TreeNode* root)
    {
        cameras = 0;
        // -1 -> node needs a camera, 0 -> node has camera, 1 -> node is covered so don't need a camera
        if (solve(root) == -1)   cameras++; //it may happen that root needs a camera but it doesn't have a parent, so will have camera itself
        return cameras;
    }

    int solve(TreeNode *root)
    {
        if (!root)   return 1; //if node is NULL, it means it doesn't need or can have a camera, so we can say it is covered

        int l = solve(root->left);
        int r = solve(root->right);

        if (l == -1 or r == -1) //my children need camera, so I'll have camera
        {
            cameras++;
            return 0; //means I have camera
        }

        if (l == 0 or r == 0)    return 1; //my child has camera, so I'm covered

        else return -1; //both my children are covered and don't have camera, so I'm not covered and will say to my parent that I need a camera
    }
};