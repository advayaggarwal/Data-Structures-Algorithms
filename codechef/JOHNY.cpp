/*
    AUTHOR:         ADVAY AGGARWAL
    INSTITUTION:    IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod     1000000007 //1e9+7  ans%mod
#define ll  long long
#define test_cases(x)   int x; cin>>x; while(x--)

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

int binary_search(int length[], int n,  int find)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + end - start / 2;
        if (length[mid] == find)   return mid;
        else if (length[mid] < find)  start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main()
{
    starter();
    test_cases(t)
    {
        int n, i;
        cin >> n;
        int length[n];
        for (i = 0; i < n; i++)  cin >> length[i];
        int k;
        cin >> k;
        int find = length[k - 1];
        sort(length, length + n);
        int ans = binary_search(length, n, find);
        cout << ans + 1 << endl;
    }
    return 0;
}