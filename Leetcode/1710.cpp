//Using Sorting
//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int>&a, vector<int>&b) {
            return a[1] > b[1];
        });

        int ans = 0, n = boxTypes.size();

        for (int i = 0; i < n && truckSize; i++)
        {
            int boxes = min(truckSize, boxTypes[i][0]);
            ans += (boxes * boxTypes[i][1]);
            truckSize -= boxes;
        }

        return ans;
    }
};

//Using Count Sort
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        vector<int>count(1001); //count[i] stores the number of boxes in which number of units per box is i
        int ans = 0, n = boxTypes.size();

        for (int i = 0; i < n; i++)  count[boxTypes[i][1]] += boxTypes[i][0];

        for (int i = 1000; i >= 0 && truckSize; i--)
        {
            int boxes = min(truckSize, count[i]);
            ans += (boxes * i);
            truckSize -= boxes;
        }

        return ans;
    }
};