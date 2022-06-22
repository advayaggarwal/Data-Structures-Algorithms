//Time complexity - O(n+k)
//Space complexity - O(n)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        vector<int>remainderFreq(k);

        for (int num : arr)   remainderFreq[(num % k + k) % k]++; //same as num%k, so that num%k is not negative in case of negative numbers

        //no. exactly divisible by k, means other no. should also be divisible by k means freq should be even
        if (remainderFreq[0] & 1)  return false;
        //iterating over the remainders, no need to check till k-1, will occur in repeated checks
        //eg- k = 10, at i = 3, we will look at 7 and, at i = 7, we will look at 3
        for (int i = 1; i <= k / 2; i++)
        {
            if (i == k - i) //remainder equal, freq should be even
            {
                if (remainderFreq[i] & 1)    return false;
            }
            //freq of remainder i should be equal to freq of remainder k-i, so that there sum is divisible by k
            if (remainderFreq[i] != remainderFreq[k - i])  return false;
        }

        return true;
    }
};