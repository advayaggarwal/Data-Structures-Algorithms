//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        sort(properties.begin(), properties.end(), [](vector<int>&p1, vector<int>&p2) {
            if (p1[0] == p2[0])  return p1[1] > p2[1];
            return p1[0] < p2[0];
        });

        int n = properties.size(), ans = 0, maxDef = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (properties[i][1] < maxDef)   ans++;
            else maxDef = properties[i][1];
        }

        return ans;
    }
};