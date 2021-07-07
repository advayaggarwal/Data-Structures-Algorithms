//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)    return 0;
        vector<int>lm(n), rm(n);
        lm[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            lm[i] = max(lm[i - 1], height[i]);
        }
        rm[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) rm[i] = max(rm[i + 1], height[i]);

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            res += (min(lm[i], rm[i]) - height[i]);
        }

        return res;
    }
};


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