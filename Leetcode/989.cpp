//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        int i = num.size() - 1, carry = 0;
        vector<int>res;
        while (k or i >= 0 or carry)
        {
            int rem = k % 10;
            k /= 10;
            int sum = carry + rem;
            if (i >= 0)  sum += num[i];
            res.push_back(sum % 10);
            carry = sum / 10;
            i--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};