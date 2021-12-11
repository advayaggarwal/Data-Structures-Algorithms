/*
In fact, we can move all chips at even positions to position 0, and move all chips
at the odd positions to position 1.
Then, we only have many chips at position 0 and other chips at position 1.
Next, we only need to move those two piles together.
Given two piles of chips located at 0 and 1 respectively, intuitively it would be less effort-taking
(i.e. less cost) to move the smaller pile to the larger one, which makes the total cost to:
Cost = min(even_cnt, odd_cnt)
*/

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minCostToMoveChips(vector<int>& position)
    {
        int odd = 0, even = 0;
        for (int i : position)
        {
            if (i & 1)   odd++;
            else even++;
        }

        return min(odd, even);
    }
};