//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num)
        {
            steps++;

            if (num & 1) num--;
            else num >>= 1;
        }

        return steps;
    }
};