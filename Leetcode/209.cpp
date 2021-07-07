//Sliding Window
//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int mn = INT_MAX;
        int n = nums.size();
        int sum = 0;
        while (j < n)
        {
            sum += nums[j];

            if (sum < target)    j++;

            else if (sum == target)
            {
                mn = min(mn, j - i + 1);
                j++;
            }

            else
            {
                while (sum > target)
                {
                    sum -= nums[i];
                    mn = min(mn, j - i + 1);
                    i++;
                }

                if (sum == target) mn = min(mn, j - i + 1);
                j++;
            }
        }

        return mn == INT_MAX ? 0 : mn;

    }
};


//Sliding Window
//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int mn = INT_MAX;
        int n = nums.size();
        int sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                mn = min(mn, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return mn == INT_MAX ? 0 : mn;

    }
};