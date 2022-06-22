//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size(), mod = 1e9 + 7, ans = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            ans = (ans + m[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++) m[arr[i] + arr[j]]++;
        }

        return ans;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target)
    {
        int n = arr.size();
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int target_sum = target - arr[i];
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                if (arr[low] + arr[high] < target_sum) low++;
                else if (arr[low] + arr[high] > target_sum) high--;
                else if (arr[low] != arr[high])
                {
                    int left = 1, right = 1;
                    while (low + 1 < high && arr[low] == arr[low + 1])
                    {
                        left++;
                        low++;
                    }

                    while (high - 1 > low && arr[high] == arr[high - 1])
                    {
                        right++;
                        high--;
                    }

                    ans += left * right;
                    ans %= mod;
                    low++;
                    high--;
                }
                else
                {
                    ans += (high - low + 1) * (high - low) / 2; //nC2 where n = high-low+1
                    ans %= mod;
                    break;
                }
            }
        }

        return ans;
    }
};