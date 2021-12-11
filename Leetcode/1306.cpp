//DFS
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        vector<bool>visited(n + 1, false); //To avoid calling same problem again and again
        return helper(arr, start, visited);
    }

    bool helper(vector<int>& arr, int index, vector<bool>&visited)
    {
        if (arr[index] == 0) return true;

        bool op1 = false, op2 = false;
        visited[index] = true;

        if (index + arr[index] < arr.size() && !visited[index + arr[index]]) op1 = helper(arr, index + arr[index], visited);
        if (index - arr[index] >= 0 && !visited[index - arr[index]]) op2 = helper(arr, index - arr[index], visited);

        return op1 or op2;
    }
};