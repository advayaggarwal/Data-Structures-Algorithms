//Sorting
//Time complexity - O(nlong)
//Space complexity - O(1)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right && nums[left] < k) {  // pruning:  nums[left] < k
            if (nums[left] + nums[right] < k) {
                left++;
            } else if (nums[left] + nums[right] > k) {
                right--;
            } else {
                left++;
                right--;
                count++;
            }
        }
        return count;
    }
};

//Using multiset
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_multiset<int>m;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto it = m.find(k - nums[i]);
            if (it != m.end())
            {
                ans++;
                m.erase(it);
            }

            else
            {
                m.insert(nums[i]);
            }
        }

        return ans;
    }
};

//Single Pass solution
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int>freq; //{num, count}
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)  freq[nums[i]]++;

        for (auto &p : freq)
        {
            if (k % 2 == 0 && p.first == k / 2)
            {
                ans += p.second / 2;
                p.second = 0;
            }

            else if (freq.count(k - p.first))
            {
                ans += min(p.second, freq[k - p.first]);
                freq[p.first] = 0;
            }
        }

        return ans;
    }
};

//Single Pass solution
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        for (auto cur : nums) {
            int complement = k - cur;
            if (freq[complement] > 0) {ans++; freq[complement]--;}
            else freq[cur]++;
        }
        return ans;
    }
};