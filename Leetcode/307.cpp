//Simple Prefix Sum
class NumArray {
public:
    vector<int>prefixSum, num;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        num = vector<int>(nums);
        prefixSum = vector<int>(n + 1);

        for (int i = 1; i <= n; i++) prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    void update(int index, int val) { //O(n)
        num[index] = val;
        for (int i = index + 1; i <= num.size(); i++) prefixSum[i] = prefixSum[i - 1] + num[i - 1];
    }

    int sumRange(int left, int right) { //O(1)
        left++; right++;
        return prefixSum[right] - prefixSum[left - 1];
    }
};

//Segment Tree
struct segmentTree
{
    int n;
    vector<int>st;

    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }

    void buildHelper(int start, int end, int node, vector<int>&v)
    {
        //base case - leaf node
        if (start == end)
        {
            st[node] = v[start];
            return;
        }

        int mid = start + (end - start) / 2;

        //left subtree is [start, mid]
        buildHelper(start, mid, 2 * node + 1, v);

        //right subtree is [mid+1, end]
        buildHelper(mid + 1, end, 2 * node + 2, v);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<int> &v)
    {
        buildHelper(0, n - 1, 0, v);
    }

    int queryHelper(int start, int end, int l, int r, int node)
    {
        //non overlapping case
        if (start > r or end < l)   return 0;

        //complete overlap
        if (start >= l && end <= r) return st[node];

        //partial overlap
        int mid = start + (end - start) / 2;
        int leftQuery = queryHelper(start, mid, l, r, 2 * node + 1);
        int rightQuery = queryHelper(mid + 1, end, l, r, 2 * node + 2);
        return leftQuery + rightQuery;
    }

    int query(int l, int r)
    {
        return queryHelper(0, n - 1, l, r, 0);
    }

    void updateHelper(int start, int end, int index, int val, int node)
    {
        //base case - leaf node
        if (start == end)
        {
            st[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) //go to left subtree
        {
            updateHelper(start, mid, index, val, 2 * node + 1);
        }

        else //go to right subtree
        {
            updateHelper(mid + 1, end, index, val, 2 * node + 2);
        }

        st[node] = st[2 * node + 1] + st[2 * node + 2]; //update the parent
    }

    void update(int index, int val)
    {
        updateHelper(0, n - 1, index, val, 0);
    }
};

class NumArray {
public:
    segmentTree tree;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.init(n);
        tree.build(nums);
    }

    void update(int index, int val) { //O(logn)
        tree.update(index, val);
    }

    int sumRange(int left, int right) { //O(logn)
        return tree.query(left, right);
    }
};