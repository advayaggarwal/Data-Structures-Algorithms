/*
Calculate the final vector of how the robot travels after executing all instructions once - it consists of
a change in position plus a change in direction.
The robot stays in the circle if and only if (looking at the final vector) it changes direction
(ie. doesn't stay pointing north), or it moves 0 i.e. (0,0).
*/

//Time complexity - O(n), where n is the size of instructions
//Space complexity - O(1)
class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        int dirX = 0, dirY = 1;
        int x = 0, y = 0;

        for (char c : instructions)
        {
            if (c == 'G')
            {
                x += dirX;
                y += dirY;
            }

            else if (c == 'L')
            {
                swap(dirX, dirY);
                dirX = -dirX;
            }

            else
            {
                swap(dirX, dirY);
                dirY = -dirY;
            }
        }

        return (x == 0 && y == 0) or !(dirX == 0 && dirY == 1);
    }
};