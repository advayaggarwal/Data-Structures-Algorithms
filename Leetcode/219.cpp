//Using unordered map
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int>m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]) && abs(i - m[nums[i]]) <= k)   return true;
            m[nums[i]] = i;
        }

        return false;
    }
};

//Using unordered set
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int>st;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)   st.erase(nums[i - k - 1]);
            if (st.count(nums[i]))   return true;
            st.insert(nums[i]);
        }

        return false;
    }
};