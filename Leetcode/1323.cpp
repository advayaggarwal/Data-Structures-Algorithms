//Time complexity - O(no of digits)
//Space complexity - O(no of digits)
class Solution {
public:
    int maximum69Number (int num)
    {
        string number = to_string(num);
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == '6')
            {
                number[i] = '9';
                break;
            }
        }

        return stoi(number);
    }
};