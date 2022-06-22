//https://www.youtube.com/watch?v=nqCM8opotjU
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n)
    {
        string num = to_string(n);

        int count = 0;

        for (int i = 1; i <= num.size() - 1; i++)   count += pow(digits.size(), i);

        int i = 0;
        while (i < num.size())
        {
            int j = 0;
            while (j < digits.size() && digits[j][0] < num[i])
            {
                count += pow(digits.size(), num.size() - 1 - i);
                j++;
            }

            if (j == digits.size() || digits[j][0] > num[i])   break;
            i++;
        }

        if (i == num.size()) count++;

        return count;
    }
};