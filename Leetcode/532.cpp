//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        unordered_map<int, int>m;
        set<pair<int, int>>s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (m.find(nums[i] - k) != m.end())    s.insert({nums[i], nums[i] - k});

            if (m.find(nums[i] + k) != m.end())    s.insert({nums[i] + k, nums[i]});

            m[nums[i]] = 1;
        }

        return s.size();
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            while (i < n && (i > 0 && nums[i] == nums[i - 1]))   i++;
            if (i >= n)  break;
            int key1 = nums[i] - k, key2 = nums[i] + k;

            bool present = binary_search(nums.begin() + i + 1, nums.end(), key1);
            if (present)    count++;

            if (key1 != key2)
            {
                present = binary_search(nums.begin() + i + 1, nums.end(), key2);
                if (present)  count++;
            }
        }

        return count;
    }
};


//Time complexity - O(n)
//Space complexity - O(n)
int findPairs(vector<int>& nums, int k)
{
    unordered_map<int, int>h;
    int res = 0;
    for (auto i : nums) h[i]++;
    for (auto i : h)
    {
        //could be i.first-k also
        if ( (!k && i.second > 1) || (k && h.find(i.first + k) != h.end()) ) res++;
    }
    return res;
}