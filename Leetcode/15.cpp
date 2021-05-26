//Hash map
//Time complexity - O(n^2 * logm), m is the no. of unique triplets, s.find(v) and s.insert(v) will take O(logm) complexity
//Space complexity - O(m), again m is the no. of unique triplets

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>m;

        for (int i = 0; i < n; i++)      m[nums[i]] = i;

        vector<vector<int>>res;
        set<vector<int>>s;  //To store unique triplets

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                vector<int>v;
                auto it = m.find(-nums[i] - nums[j]);
                if (it != m.end() && it->second != i && it->second != j)
                {
                    v = {nums[i], nums[j], nums[it->second]};

                    sort(v.begin(), v.end()); //sorting so that set will recognise duplicate triplets

                    if (s.find(v) == s.end())
                    {
                        res.push_back(v);
                        s.insert(v);
                    }
                }
            }
        }

        return res;
    }
};


//2 Pointer approach
//Time complexity - O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>>res;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)   continue; //As if nums[i] is greater than 0 then all elements right to i will also be greater than 0 so their's sum can't be 0
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) //To remove duplicates
            {
                int low = i + 1, high = n - 1, target_sum = -nums[i];

                while (low < high)
                {
                    if (nums[low] + nums[high] < target_sum) low++;
                    else if (nums[low] + nums[high] > target_sum) high--;
                    else
                    {
                        vector<int>triplet = {nums[i], nums[low], nums[high]};
                        res.push_back(triplet);

                        while (low < high && nums[low] == nums[low + 1])   low++; //To remove duplicates
                        while (low < high && nums[high] == nums[high - 1])   high--; //To remove duplicates

                        low++;
                        high--;
                    }
                }

            }
        }

        return res;
    }
};