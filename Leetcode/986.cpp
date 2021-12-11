//Time Complexity: O(M+N), where M,N are the lengths of firstList and secondList respectively.
//Space Complexity: O(M+N), the maximum size of the answer.
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
    {
        if (firstList.size() == 0 or secondList.size() == 0) return {};

        vector<vector<int>>res;
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            int a = max(firstList[i][0], secondList[j][0]);
            int b = min(firstList[i][1], secondList[j][1]);

            if (a <= b)  res.push_back({a, b});

            if (firstList[i][1] < secondList[j][1])  i++;
            else j++;
        }

        return res;
    }
};