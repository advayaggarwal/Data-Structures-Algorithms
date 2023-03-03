//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [&](vector<int>&a, vector<int>&b) {
            if (a[0] == b[0])    return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>>res;
        for (auto v : people)
        {
            auto it = res.begin() + v[1];
            res.insert(it, v); //shifting every number from ith index to (n-1)th index by 1 position to the right
            //basically inserting v at the it
        }

        return res;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        int n = people.size();
        sort(people.begin(), people.end(), [&](vector<int>&a, vector<int>&b) {
            if (a[0] == b[0])    return a[1] < b[1];
            return a[0] < b[0];
        });

        //Put elements at correct position
        vector<vector<int>> ans(n, vector<int>(2, -1));
        for (int i = 0; i < n; i++)
        {
            int count = people[i][1];
            for (int j = 0; j < n; j++)
            {
                if (ans[j][0] == -1 && count == 0) //got the correct position for people[i]
                {
                    ans[j] = people[i];
                    break;
                }

                else if (ans[j][0] == -1 || ans[j][0] >= people[i][0])   count -= 1;
            }
        }

        return ans;
    }
};