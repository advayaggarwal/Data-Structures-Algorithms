//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>res(n);

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])   count++;
            }
            res[i] = count;
        }

        return res;
    }
};

//BST
//Average case Time complexity - O(nlogn)
//Worst case Time complexity - O(n^2)
class Node {
public:
    int val;
    Node *left;
    Node *right;
    int count;

    Node(int val)
    {
        this->val = val;
        count = 1;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>res(n);

        if (n <= 1)  return res;

        Node *root = new Node(nums[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            int count = insertNode(root, nums[i]);
            res[i] = count;
        }

        return res;
    }

    int insertNode(Node *root, int n)
    {
        int ans = 0;
        Node *temp = new Node(n);
        bool isConnected = false;
        while (!isConnected && root)
        {
            if (root->val < n)
            {
                ans += root->count;
                if (!root->right)
                {
                    root->right = temp;
                    isConnected = true;
                }
                else root = root->right;
            }

            else
            {
                root->count += 1;
                if (!root->left)
                {
                    root->left = temp;
                    isConnected = true;
                }
                else root = root->left;
            }
        }

        return ans;
    }
};

//Merge Sort - Inversion count for every index
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>res(n);
        if (n <= 1)  return res;

        vector<pair<int, int>>vals;
        for (int i = 0; i < n; i++)  vals.push_back({nums[i], i});

        mergeSortAndCount(vals, 0, n - 1, res);

        return res;
    }

    void mergeSortAndCount(vector<pair<int, int>>&vals, int start, int end, vector<int>&res)
    {
        if (start >= end)  return;

        int mid = (start + end) / 2;

        mergeSortAndCount(vals, start, mid, res);
        mergeSortAndCount(vals, mid + 1, end, res);

        int leftPos = start;
        int rightPos = mid + 1;
        vector<pair<int, int>> merged;
        int numElemsRightArrayLessThanLeftArray = 0;

        while (leftPos <= mid && rightPos <= end)
        {
            if (vals[leftPos].first > vals[rightPos].first)
            {
                numElemsRightArrayLessThanLeftArray++;
                merged.push_back(vals[rightPos]);
                rightPos++;
            }
            else
            {
                merged.push_back(vals[leftPos]);
                res[vals[leftPos].second] += numElemsRightArrayLessThanLeftArray;
                leftPos++;
            }
        }

        while (leftPos <= mid)
        {
            merged.push_back(vals[leftPos]);
            res[vals[leftPos].second] += numElemsRightArrayLessThanLeftArray;
            leftPos++;
        }

        while (rightPos <= end)
        {
            numElemsRightArrayLessThanLeftArray++;
            merged.push_back(vals[rightPos]);
            rightPos++;
        }

        int pos = start;
        for (auto p : merged) vals[pos++] = p;
    }
};