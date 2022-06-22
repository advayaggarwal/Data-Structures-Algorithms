//Using Binary Search and Prefix Sum
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen)
    {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());

        vector<int>prefixSumLen(n);
        prefixSumLen[0] = tiles[0][1] - tiles[0][0] + 1;
        vector<int>tile;
        tile.push_back(tiles[0][1]);

        for (int i = 1; i < n; i++)
        {
            prefixSumLen[i] = prefixSumLen[i - 1] + tiles[i][1] - tiles[i][0] + 1;
            tile.push_back(tiles[i][1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) //place carpet starting at the ith tile
        {
            int finish = tiles[i][0] + carpetLen - 1; //ending point of the carpet
            int index = lower_bound(tile.begin(), tile.end(), finish) - tile.begin(); //finding in which segment ending point lies
            int len = (index == 0) ? 0 : prefixSumLen[index - 1] - (i > 0 ? prefixSumLen[i - 1] : 0); //len of fully covered tiles

            if (index != n && tiles[index][0] <= finish)    len += finish - tiles[index][0] + 1; //if it partially covers last segment

            ans = max(ans, len);
        }

        return ans;
    }
};

//Sliding Window
//Time complexity - O(nlogn)
//Space complexity - O(1)
/*
Intuition: it's always better to place a carpet at the beginning of a white tile range. The reason is, if you shift a carpet one tile forward, you might cover another white tile, but you definitely uncover the previous white tile.

So, we sort tile ranges, and check how many white tiles we can cover, starting from the beginning of each range.

To avoid TLE, we "drag" our carpet over ranges using a sliding window. Applying sliding window is a bit tricky here:

We track the current placement of the carpet (tiles[j][0]).
When we can cover tiles[i], we add those tiles to cover.
Otherwise, we partially cover tiles[i]
We remove tiles[j] from cover.
We move the placement of the carpet (++j)
*/
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len)
    {
        int res = 0, j = 0, cover = 0;//cover is length of white tiles covered by carpet in current window
        sort(t.begin(), t.end());
        for (int i = 0; i < t.size();)//carpet starts from j and end at i
        {
            if (j == i || t[j][0] + len > t[i][1]) //carpet starting from j is exceeding this window(as this window is ending at i)
            {
                cover += t[i][1] - t[i][0] + 1;//this window is being extended to cover this patch also
                res = max(res, cover);
                ++i;//let this window try to cover next patch by expanding its right end
            }
            else//carpet starting from jth patch is not able to cover this whole patch at i
            {
                res = max(res, cover + max(0, t[j][0] + len - t[i][0]));
                /* Partial length covered by
                carpet in this patch
                */
                cover -= (t[j][1] - t[j][0] + 1);//window will slide towards right hence remove the contribution of cover given by left most
//patch of current window.
                ++j;//slide the window towards its right
            }
        }
        return min(res, len);
    }
};