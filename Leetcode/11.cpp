class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while (l < r)
        {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }

        return maxArea;
    }
};

/*Note

If height[i] == height[j]
then,
You need to prove that in this case, it does not matter whether you perform i++ or j--,
because if h[i] == h[j], neither (i+1, j) nor (i, j-1) can be potential solutions because the area obtained is
necessarily smaller than (i, j) because,
then a larger container (k, j) where k > i would need to satisfy
j - k > j - i (because the container's height is bounded by h[j]), which is impossible since k > i.

*/