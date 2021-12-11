//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int>s;
        while (n != 1)
        {
            int sum = 0;
            while (n)
            {
                int t = n % 10;
                sum += t * t;
                n /= 10;
            }
            //if we have seen this no before, it means we are stuck inside the loop, therefore not a happy number
            if (s.find(sum) != s.end())    return false;

            s.insert(sum);
            n = sum;
        }

        return true;
    }
};