//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int>m;
        int n = nums.size();
        for (int num : nums)
        {
            m[num]++;
            if (m[num] > n / 2)    return num;
        }
        return -1;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate;
        int count = 0;
        for (int &num : nums)
        {
            if (count == 0)    candidate = num;

            count += candidate == num ? 1 : -1;
        }

        return candidate;
    }
};