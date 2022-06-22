//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minMaxGame(vector<int>& nums)
    {
        while (nums.size() > 1)
        {
            vector<int>temp;
            bool flag = false;
            for (int i = 0; i < nums.size(); i += 2)
            {
                if (!flag)   temp.push_back(min(nums[i], nums[i + 1]));
                else    temp.push_back(max(nums[i], nums[i + 1]));

                flag = !flag;
            }

            nums = temp;
        }

        return nums[0];
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int minMaxGame(vector<int>& nums)
    {
        int n = nums.size();
        while (n > 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (!(i & 1))   nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                else    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }

            n /= 2;
        }

        return nums[0];
    }
};