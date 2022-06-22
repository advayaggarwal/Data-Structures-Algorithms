//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int>s;
        int n = pushed.size(), j = 0;

        for (int &x : pushed)
        {
            s.push(x);
            while (!s.empty() && j < n && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};