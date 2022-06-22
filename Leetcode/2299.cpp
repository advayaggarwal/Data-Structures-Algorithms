//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool strongPasswordCheckerII(string p)
    {
        if (p.size() < 8) return false;
        bool digit = false, sp = false, upper = false, lower = false;

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] >= '0' && p[i] <= '9')  digit = true;
            else if (p[i] >= 'A' && p[i] <= 'Z') upper = true;
            else if (p[i] >= 'a' && p[i] <= 'z') lower = true;
            else    sp = true; //as string only contains digit, low, upper and special chars

            if (i > 0 && p[i] == p[i - 1]) return false;
        }

        return digit && sp && upper && lower;
    }
};