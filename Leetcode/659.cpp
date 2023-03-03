//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int, int>availability, vacancy;

        for (int num : nums) availability[num]++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (availability[nums[i]] <= 0)  continue;
            else if (vacancy[nums[i]] > 0)
            {
                availability[nums[i]]--;
                vacancy[nums[i]]--;
                vacancy[nums[i] + 1]++;
            }
            else if (availability[nums[i]] > 0 && availability[nums[i] + 1] > 0 && availability[nums[i] + 2] > 0)
            {
                availability[nums[i]]--;
                availability[nums[i] + 1]--;
                availability[nums[i] + 2]--;
                vacancy[nums[i] + 3]++;
            }
            else return false;
        }

        return true;
    }
};