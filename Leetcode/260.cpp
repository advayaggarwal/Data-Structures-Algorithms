class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        vector<int>res(2, 0);

        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }

        int i;

        for (i = 0; i < 31; i++)
        {
            if (ans & (1 << i))    break;
        }

        for (int j = 0; j < n; j++)
        {
            if (nums[j] & (1 << i))    res[0] ^= nums[j];
        }

        res[1] = res[0] ^ ans;


        return res;

    }
};