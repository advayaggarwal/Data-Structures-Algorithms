//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool validUtf8(vector<int>& data)
    {
        int n = data.size(), remainingBytes = 0;

        for (int i = 0; i < n; i++)
        {
            if (remainingBytes == 0)
            {
                if ((data[i] >> 7) == 0) //start of 1 byte char
                    remainingBytes = 0;

                else if ((data[i] >> 5) == 0b110) //start of 2 byte char
                    remainingBytes = 1;

                else if ((data[i] >> 4) == 0b1110) //start of 3 byte char
                    remainingBytes = 2;

                else if ((data[i] >> 3) == 0b11110) //start of 4 byte char
                    remainingBytes = 3;

                else return false;
            }

            else
            {
                if ((data[i] >> 6) == 0b10)    remainingBytes--;
                else return false;
            }
        }

        return remainingBytes == 0;
    }
};