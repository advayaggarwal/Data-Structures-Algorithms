//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>>res;
        int n = nums.size();
        if (n == 0)  return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int target_2 = target - nums[i] - nums[j];
                //2 sum for target_2

                int front = j + 1;
                int back = n - 1;
                while (front < back)
                {
                    int two_sum = nums[front] + nums[back];

                    if (two_sum > target_2) back--;

                    else if (two_sum < target_2) front++;
                    else
                    {
                        vector<int>quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);

                        //Processing the duplicates of num3
                        while (front < back and nums[front] == quad[2])  front++;
                        //Processing the duplicates of num4
                        while (front < back and nums[back] == quad[3])   back--;

                    }
                }
                //Processing the duplicates of num2
                while (j + 1 < n and nums[j + 1] == nums[j]) j++;
            }

            //Processing the duplicates of num1
            while (i + 1 < n and nums[i + 1] == nums[i]) i++;
        }

        return res;
    }
};