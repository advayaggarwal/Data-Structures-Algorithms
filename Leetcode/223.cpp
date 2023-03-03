//Time complexity - O(1)
//Space complexity - O(1)
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        //calculate x overlap
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int xOverlap = right - left;


        //calculate x overlap
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int yOverlap = top - bottom;

        int commonArea = 0;
        if (xOverlap > 0 && yOverlap > 0)    commonArea = xOverlap * yOverlap;

        return area1 + area2 - commonArea;
    }
};