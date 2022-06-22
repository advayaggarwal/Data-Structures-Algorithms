//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special)
    {
        sort(special.begin(), special.end());
        int low = bottom, ans = 0;

        for (int i = 0; i < special.size(); i++)
        {
            ans = max(ans, special[i] - low);
            low = special[i] + 1;
        }

        ans = max(ans, top - low + 1);

        return ans;
    }
};

//Same as above, with shorter code
int maxConsecutive(int bottom, int top, vector<int>& A)
{
    sort(begin(A), end(A));
    int n = A.size(), res = max(A[0] - bottom, top - A[n - 1]);
    for (int i = 1; i < n; ++i) res = max(res, A[i] - A[i - 1] - 1);
    return res;
}