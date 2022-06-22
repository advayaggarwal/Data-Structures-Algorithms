//Approach 1 - Sorting
//Time complexity - O(nlogn)
//Space complexity - O(1)



//Approach 2
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int>s;
        for (int i = 0; i < n; i++)
        {
            if (s.find(nums[i]) != s.end())    return nums[i];
            else s.insert(nums[i]);
        }

        return -1;
    }
};


//Approach 3
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0)   nums[index] = -nums[index];
            else    return index + 1;
        }
        return -1;
    }
};



//Approach 4
// Slow and Fast pointer, Floyd's Algo
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};