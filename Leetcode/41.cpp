//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        unordered_set<int>s(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 1; i <= n; i++)
        {

            if (s.find(i) == s.end())  return i;
        }

        return n + 1;

    }
};


// Intuition
// The idea over here is let's place number 3 at index 2, 2 at index 1, 1 at index 0, so on and so forth
// Let's leave -ve number as they are.
// Let's leave numbers > N as they are. Ignore them
// Answer would be - The first index 'i' that doesnt have 'i+1' in its value

//Time complexity - O(n)
//Space complexity - O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1])//swap until value at index i is correct i.e < 1 or > n or == i+1
            {
                swap(nums[i], nums[nums[i] - 1]);
            }

        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1; //i.e every number from 1-n is present then the first missing positive is for sure n+1
    }
};