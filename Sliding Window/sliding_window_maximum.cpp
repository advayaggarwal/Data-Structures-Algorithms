#include <bits/stdc++.h>
using namespace std;
#define mod     1000000007 //1e9+7  ans%mod
#define ll  long long int
#define test_cases(x)   int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

void starter()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>res;
    int i = 0, j = 0;
    deque<int>dq;

    while (j < n)
    {
        while (!dq.empty() and dq.back() < nums[j])   dq.pop_back(); //removing the useless elements

        dq.push_back(nums[j]);

        if (j - i + 1 < k)   j++;
        else
        {
            res.push_back(dq.front());
            if (dq.front() == nums[i]) dq.pop_front();
            i++;
            j++;
        }
    }

    return res;
}



int main()
{
    starter();
    int n, k;
    cin >> n >> k;
    vi nums(n);
    for (int i = 0; i < n; i++)  cin >> nums[i];
    vi res = maxSlidingWindow(nums, k);
    for (int e : res)  cout << e << " ";
}