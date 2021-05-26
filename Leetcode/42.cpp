//Time complexity - O(n)
//Space complexity - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)    return 0;
        long long int res = 0;
        int l = 0, r = n - 1;
        int leftmax = 0, rightmax = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= leftmax)  leftmax = height[l];
                else
                {
                    res += leftmax - height[l];
                }
                l++;
            }
            else
            {
                if (height[r] >= rightmax) rightmax = height[r];
                else
                {
                    res += rightmax - height[r];
                }
                r--;
            }
        }
        return res;
    }
};