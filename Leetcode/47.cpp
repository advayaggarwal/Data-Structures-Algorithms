//Time complexity - O(n*logn*n!)
//Space complexity - O(# unique permutations)
//Using set
class Solution {
public:

    void helper(vector<int>& nums, int index, set<vector<int>>&unique_permutations)
    {
        if (index == nums.size())
        {
            unique_permutations.insert(nums);
            return ;
        }

        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            helper(nums, index + 1, unique_permutations);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>unique_permutations;
        helper(nums, 0, unique_permutations);

        for (auto v : unique_permutations)    ans.push_back(v);

        return ans;

    }
};

//Using unordered set, though we have to come up with the hash, i.e have to overload () operator
//Time complexity - O(n*n!)
//Space complexity - O(# unique permutations)
class Solution {
public:

    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    void helper(vector<int>& nums, int index, unordered_set<vector<int>, VectorHash>&unique_permutations)
    {
        if (index == nums.size())
        {
            unique_permutations.insert(nums);
            return ;
        }

        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            helper(nums, index + 1, unique_permutations);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_set<vector<int>, VectorHash>unique_permutations;
        helper(nums, 0, unique_permutations);

        for (auto v : unique_permutations)    ans.push_back(v);

        return ans;

    }
};



//Optimised solution
//Time complexity - O(n*n!)
//Space complexity - O(n)
class Solution {
public:

    void helper(vector<int>& nums, int index, vector<vector<int>>&ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return ;
        }

        unordered_set<int>s;

        for (int j = index; j < nums.size(); j++)
        {
            if (s.find(nums[j]) != s.end())    continue; //i.e we've already used nums[j] at position index, if we again use-
            //it will give duplicate permutations
            s.insert(nums[j]);
            swap(nums[index], nums[j]);
            helper(nums, index + 1, ans);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(nums, 0, ans);
        return ans;
    }
};

//Time complexity - O(n*n!)
//Space complexity - O(n), considering stack space, else O(1)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        helper(0, nums, ans);
        return ans;
    }

    void helper(int i, vector<int>nums, vector<vector<int>>&ans)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            if (j != i && nums[i] == nums[j])  continue;
            swap(nums[i], nums[j]);
            helper(i + 1, nums, ans);
        }
    }
};