//Prefix and Suffix Sum
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int n = cardPoints.size(), sum = 0;
        vector<int> cummulativeSumFromFront(n + 1, 0), cummulativeSumFromBehind(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            sum += cardPoints[i];
            cummulativeSumFromFront[i + 1] = sum;
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += cardPoints[i];
            cummulativeSumFromBehind[i] = sum;
        }

        // Reversing is optional. I reversed it so that it would be easy
        // to access sum of last (k-i) elements by just indexing at [k-i]
        // Otherwise, I would have had to index it at [n-k+i] which would
        // have made it difficult to read.
        reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());

        int answer = 0;
        for (int i = 0; i <= k; i++)
        {
            answer = max(answer,
                         cummulativeSumFromFront[i] // Sum of first 'i' cards.
                         + cummulativeSumFromBehind[k - i]); // Sum of last 'k-i' cards.
        }
        return answer;
    }
};

//Sliding Window - Find the smallest subarray sum of length n - k
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int total = 0, n = cardPoints.size();
        for (int x : cardPoints) total += x;

        //minimum points you can make by taking n-k cards consecutively i.e. sliding window of size n-k
        int i = 0, j = 0, ans = INT_MAX, sum = 0;
        k = n - k;

        while (j < n)
        {
            sum += cardPoints[j];
            if (j - i + 1 == k)
            {
                ans = min(ans, sum);
                sum -= cardPoints[i++];
            }
            j++;
        }

        return ans == INT_MAX ? total : total - ans;
    }
};