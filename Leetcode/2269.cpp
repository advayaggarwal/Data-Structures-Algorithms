//Time complexity - O(n*k)
//Space complexity - O(1)
class Solution {
public:
    int divisorSubstrings(int num, int k)
    {
        string nums = to_string(num);
        int n = nums.size(), ans = 0;

        for (int i = 0; i <= n - k; i++)
        {
            string no = nums.substr(i, k);
            int number = stoi(no);
            if (number != 0 && num % number == 0) ans++;
        }

        return ans;
    }
};