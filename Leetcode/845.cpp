//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        int n = arr.size();
        int longest = 0;

        for (int i = 1; i < n - 1;) //first & last element cannot be peak
        {
            //Check arr[i] is peak or not
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int count = 1;
                int j = i;
                while (j > 0 && arr[j] > arr[j - 1]) //count backwards (left)
                {
                    count++;
                    j--;
                }

                while (i < n - 1 && arr[i] > arr[i + 1]) //count forward (right)
                {
                    count++;
                    i++;
                }

                longest = max(longest, count);
            }

            else i++;
        }

        return longest;
    }
};