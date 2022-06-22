//Time complexity - O(min(m,n))
//Space complexity - O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if (n == 0)  return true;
        int m = flowerbed.size();

        for (int i = 0; i < m && n; i++)
        {
            if (flowerbed[i] == 0)
            {
                if ((i == 0 or flowerbed[i - 1] == 0) && (i == m - 1 or flowerbed[i + 1] == 0))
                {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }

        return n == 0;
    }
};