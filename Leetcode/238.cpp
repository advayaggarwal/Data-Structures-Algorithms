class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p1 = 1, p2 = 1;
        int n = nums.size();
        vector<int>res(n, 1);

        for (int i = 0; i < n; i++)
        {
            res[i] *= p1; //Prefix product
            p1 *= nums[i];

            int j = n - i - 1;
            res[j] *= p2; //Suffix product
            p2 *= nums[j];
        }
        return res;
    }
};