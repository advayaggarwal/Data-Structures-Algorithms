//Sorting using custom comparator
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
            string s1 = to_string(a) + to_string(b);
            string s2 = to_string(b) + to_string(a);
            return s1 > s2;
        });

        int n = nums.size();
        if (nums[0] == 0)    return "0";
        string res;
        for (int i = 0; i < n; i++)    res += to_string(nums[i]);

        return res;
    }
};